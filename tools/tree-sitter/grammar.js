const binops = [
  ["+", 1],
  ["-", 1],
  ["*", 2],
  ["/", 2],
  ["%", 2],
  ["&", 3],
  ["|", 3],
  ["==", 4],
  ["!=", 4],
  [">", 4],
  ["<", 4],
  [">=", 4],
  ["<=", 4],
];

// Helper functions
function sep(rule, separator) {
  return optional(sep1(rule, separator));
}

function sep1(rule, separator) {
  return seq(rule, repeat(seq(separator, rule)));
}

module.exports = grammar({
  name: "blossom",

  name: "blossom",

  extras: ($) => [$.comment, /\s/],

  // Add precedence rules
  precedences: ($) => [["variable_definition", "optional_value"]],

  // Add conflicts resolution
  conflicts: ($) => [[$.variable_definition, $.optional_value]],

  rules: {
    // Change optional_value to use prec
    optional_value: ($) => prec.left("optional_value", seq("None")),

    // Change variable_definition to use prec
    variable_definition: ($) =>
      prec.left(
        "variable_definition",
        seq(
          $.identifier,
          ":",
          choice($.primitive_type, $.collection_type),
          optional(seq("=", choice($.literal, "None"))),
        ),
      ),

    // Comments
    comment: ($) =>
      choice(
        seq("//", /.*/), // Single line comment
        seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/"), // Multi line comment
      ),

    // Module system
    module_declaration: ($) => seq("@module", $.identifier),

    import_declaration: ($) =>
      seq("@import", $.module_path, optional(seq("as", $.identifier))),

    using_declaration: ($) => seq("@using", $.module_path),

    module_path: ($) => sep1($.identifier, "."),

    // Identifiers and literals
    identifier: ($) => /[a-zA-Z][a-zA-Z0-9_]*/,

    literal: ($) =>
      choice(
        $.integer,
        $.float,
        $.string,
        $.boolean,
        $.binary,
        $.optional_value,
        $.collection_literal,
      ),

    integer: ($) => /-?\d+(_\d+)*/,
    float: ($) => /-?\d+\.\d+([eE][+-]?\d+)?/,
    string: ($) =>
      choice(seq('"', repeat(choice(/[^"\\]/, /\\./)), '"'), $.string_template),
    boolean: ($) => choice("True", "False"),
    binary: ($) =>
      choice(
        /0b[01]+/,
        /0x[0-9a-fA-F]+/,
        /#\[[0-9a-fA-F]{2}(\s[0-9a-fA-F]{2})*\]/,
      ),

    // Added missing definitions
    optional_value: ($) => seq("None"),
    collection_literal: ($) =>
      choice($.list_literal, $.tuple_literal, $.record_literal),
    list_literal: ($) => seq("[", sep($.expression, ","), "]"),
    tuple_literal: ($) => seq("(", sep1($.expression, ","), ")"),
    record_literal: ($) => seq("{", sep($.record_field_value, ","), "}"),
    record_field_value: ($) => seq($.identifier, ":", $.expression),
    string_template: ($) =>
      seq(
        "`",
        repeat(choice(/[^`$\\]/, /\\./, seq("${", $.expression, "}"))),
        "`",
      ),

    // Variable definition
    variable_definition: ($) =>
      seq(
        $.identifier,
        ":",
        choice($.primitive_type, $.collection_type),
        optional(seq("=", choice($.literal, "None"))),
      ),

    // Types and type definitions
    type_definition: ($) =>
      seq(
        repeat($.decorator),
        $.identifier,
        ":=",
        $.type_expression,
        optional(choice(seq("->", $.constraint_expression), $.where_clause)),
      ),

    // Added missing definitions
    decorator: ($) => seq("@", $.identifier, optional($.decorator_args)),
    decorator_args: ($) => seq("(", sep($.expression, ","), ")"),
    constraint_expression: ($) => $.expression,
    where_clause: ($) => seq("where", $.expression),

    type_expression: ($) =>
      choice($.primitive_type, $.collection_type, $.enum_definition),

    // Added missing definition
    enum_definition: ($) => seq("enum", "{", sep1($.enum_variant, ","), "}"),
    enum_variant: ($) =>
      seq($.identifier, optional(seq("(", sep1($.type_expression, ","), ")"))),

    primitive_type: ($) =>
      choice("None", "Integer", "Float", "String", "Boolean", "Binary"),

    collection_type: ($) =>
      choice($.list_type, $.tuple_type, $.record_type, $.optional_type),

    list_type: ($) => seq("List", "(", $.type_expression, ")"),
    tuple_type: ($) => seq("(", sep1($.type_expression, ","), ")"),
    record_type: ($) => seq("{", sep1($.record_field, ","), "}"),
    record_field: ($) => seq($.identifier, ":", $.type_expression),
    optional_type: ($) => seq("Optional", "(", $.type_expression, ")"),

    // Functions
    function_definition: ($) =>
      seq(
        repeat($.decorator),
        $.identifier,
        optional($.parameters),
        optional(seq(":", $.type_expression)),
        optional($.error_spec),
        "->",
        $.block,
      ),

    parameters: ($) => seq("(", sep($.parameter, ","), ")"),
    parameter: ($) => seq($.identifier, ":", $.type_expression),

    // Added missing definition
    block: ($) => seq("{", repeat($.statement), "}"),
    statement: ($) =>
      choice($.expression, $.variable_definition, $.return_statement),
    return_statement: ($) => seq("return", $.expression),

    // Error handling
    error_spec: ($) => seq("!", choice($.identifier, $.error_tuple)),
    error_tuple: ($) => seq("(", sep1($.identifier, ","), ")"),

    // Expressions
    expression: ($) =>
      choice(
        $.literal,
        $.identifier,
        $.match_expression,
        $.throw_expression,
        $.binary_expression,
        $.pipeline_expression,
      ),

    // Added missing definition
    throw_expression: ($) => seq("throw", $.expression),
    pipeline_expression: ($) => seq($.expression, "|>", $.expression),

    binary_expression: ($) =>
      choice(
        ...binops.map(([operator, precedence]) =>
          prec.left(precedence, seq($.expression, operator, $.expression)),
        ),
      ),

    // Patterns and match expressions
    match_expression: ($) =>
      seq("match", $.expression, "->", "{", repeat1($.match_arm), "}"),

    match_arm: ($) => seq($.match_pattern, "->", choice($.expression, $.block)),

    match_pattern: ($) =>
      choice(
        $.literal,
        "_",
        seq($.identifier, ":", $.type_expression),
        seq("(", sep1($.match_pattern, ","), ")"),
      ),
  },

  // Helper functions
  conflicts: ($) => [],

  precedences: ($) => [],
});
