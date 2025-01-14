; languages/blossom/highlights.scm
; Keywords
(
  [
    "match"
    "where"
    "when"
    "throw"
  ] @keyword
)

; Module-related keywords
(
  [
    "@module"
    "@import"
    "@using"
  ] @keyword.module
)

; Function-related keywords
(
  [
    "@pure"
    "@public"
  ] @keyword.function
)

; Operators
(
  [
    "->"     ; function arrow
    "|>"     ; pipeline
    "!>"     ; error pipeline
    ":>"     ; function schema
    ":="     ; type assignment
    "..."    ; spread
    "!"      ; logical not
    "&"      ; logical and
    "|"      ; logical or
    "=="     ; equality
    "!="     ; inequality
    ">="     ; greater or equal
    "<="     ; less or equal
    "+"      ; arithmetic
    "-"      ; arithmetic
    "*"      ; arithmetic
    "/"      ; arithmetic
    "%"      ; arithmetic
  ] @operator
)

; Types
(
  [
    "Integer"
    "Float"
    "String"
    "Boolean"
    "None"
    "List"
    "True"
    "False"
  ] @type
)

; Comments
(comment) @comment

; Strings
(string) @string

; Numbers
(number) @number

; Function definitions
(function_definition
  name: (identifier) @function)

; Type definitions
(type_definition
  name: (identifier) @type.definition)

; Variables
(variable_declaration
  name: (identifier) @variable)

; Function calls
(function_call
  function: (identifier) @function.call)

; Module names
(module_name) @namespace

; Template parameters
(template_parameter) @type.parameter

; Errors
(error_type) @type.error
