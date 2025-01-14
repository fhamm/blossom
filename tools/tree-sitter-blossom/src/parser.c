#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 9
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 59
#define ALIAS_COUNT 0
#define TOKEN_COUNT 57
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_None = 1,
  anon_sym_COLON = 2,
  anon_sym_EQ = 3,
  anon_sym_SLASH_SLASH = 4,
  aux_sym_comment_token1 = 5,
  anon_sym_SLASH_STAR = 6,
  aux_sym_comment_token2 = 7,
  anon_sym_SLASH = 8,
  anon_sym_as = 9,
  anon_sym_DOT = 10,
  anon_sym_DQUOTE = 11,
  aux_sym_string_token2 = 12,
  anon_sym_True = 13,
  anon_sym_False = 14,
  aux_sym_binary_token1 = 15,
  aux_sym_binary_token2 = 16,
  aux_sym_binary_token3 = 17,
  anon_sym_LBRACK = 18,
  anon_sym_COMMA = 19,
  anon_sym_RBRACK = 20,
  anon_sym_LPAREN = 21,
  anon_sym_RPAREN = 22,
  anon_sym_LBRACE = 23,
  anon_sym_RBRACE = 24,
  anon_sym_BQUOTE = 25,
  anon_sym_DOLLAR_LBRACE = 26,
  anon_sym_COLON_EQ = 27,
  anon_sym_DASH_GT = 28,
  anon_sym_AT = 29,
  anon_sym_where = 30,
  anon_sym_enum = 31,
  anon_sym_Integer = 32,
  anon_sym_Float = 33,
  anon_sym_String = 34,
  anon_sym_Boolean = 35,
  anon_sym_Binary = 36,
  anon_sym_List = 37,
  anon_sym_Optional = 38,
  anon_sym_return = 39,
  anon_sym_BANG = 40,
  anon_sym_throw = 41,
  anon_sym_PIPE_GT = 42,
  anon_sym_PLUS = 43,
  anon_sym_DASH = 44,
  anon_sym_STAR = 45,
  anon_sym_PERCENT = 46,
  anon_sym_AMP = 47,
  anon_sym_PIPE = 48,
  anon_sym_EQ_EQ = 49,
  anon_sym_BANG_EQ = 50,
  anon_sym_GT = 51,
  anon_sym_LT = 52,
  anon_sym_GT_EQ = 53,
  anon_sym_LT_EQ = 54,
  anon_sym_match = 55,
  anon_sym__ = 56,
  sym_optional_value = 57,
  sym_comment = 58,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_None] = "None",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_SLASH_SLASH] = "//",
  [aux_sym_comment_token1] = "comment_token1",
  [anon_sym_SLASH_STAR] = "/*",
  [aux_sym_comment_token2] = "comment_token2",
  [anon_sym_SLASH] = "/",
  [anon_sym_as] = "as",
  [anon_sym_DOT] = ".",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token2] = "string_token2",
  [anon_sym_True] = "True",
  [anon_sym_False] = "False",
  [aux_sym_binary_token1] = "binary_token1",
  [aux_sym_binary_token2] = "binary_token2",
  [aux_sym_binary_token3] = "binary_token3",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_DOLLAR_LBRACE] = "${",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_AT] = "@",
  [anon_sym_where] = "where",
  [anon_sym_enum] = "enum",
  [anon_sym_Integer] = "Integer",
  [anon_sym_Float] = "Float",
  [anon_sym_String] = "String",
  [anon_sym_Boolean] = "Boolean",
  [anon_sym_Binary] = "Binary",
  [anon_sym_List] = "List",
  [anon_sym_Optional] = "Optional",
  [anon_sym_return] = "return",
  [anon_sym_BANG] = "!",
  [anon_sym_throw] = "throw",
  [anon_sym_PIPE_GT] = "|>",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_PERCENT] = "%",
  [anon_sym_AMP] = "&",
  [anon_sym_PIPE] = "|",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_GT] = ">",
  [anon_sym_LT] = "<",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_match] = "match",
  [anon_sym__] = "_",
  [sym_optional_value] = "optional_value",
  [sym_comment] = "comment",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_None] = anon_sym_None,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_SLASH_SLASH] = anon_sym_SLASH_SLASH,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [anon_sym_SLASH_STAR] = anon_sym_SLASH_STAR,
  [aux_sym_comment_token2] = aux_sym_comment_token2,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_as] = anon_sym_as,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [anon_sym_True] = anon_sym_True,
  [anon_sym_False] = anon_sym_False,
  [aux_sym_binary_token1] = aux_sym_binary_token1,
  [aux_sym_binary_token2] = aux_sym_binary_token2,
  [aux_sym_binary_token3] = aux_sym_binary_token3,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_DOLLAR_LBRACE] = anon_sym_DOLLAR_LBRACE,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_where] = anon_sym_where,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_Integer] = anon_sym_Integer,
  [anon_sym_Float] = anon_sym_Float,
  [anon_sym_String] = anon_sym_String,
  [anon_sym_Boolean] = anon_sym_Boolean,
  [anon_sym_Binary] = anon_sym_Binary,
  [anon_sym_List] = anon_sym_List,
  [anon_sym_Optional] = anon_sym_Optional,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_throw] = anon_sym_throw,
  [anon_sym_PIPE_GT] = anon_sym_PIPE_GT,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_match] = anon_sym_match,
  [anon_sym__] = anon_sym__,
  [sym_optional_value] = sym_optional_value,
  [sym_comment] = sym_comment,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_None] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH_STAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_comment_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_as] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_True] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_False] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_binary_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_binary_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_binary_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_where] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Integer] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_String] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Binary] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_List] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Optional] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_throw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_match] = {
    .visible = true,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [sym_optional_value] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(78);
      if (lookahead == '!') ADVANCE(124);
      if (lookahead == '"') ADVANCE(95);
      if (lookahead == '#') ADVANCE(4);
      if (lookahead == '$') ADVANCE(72);
      if (lookahead == '%') ADVANCE(130);
      if (lookahead == '&') ADVANCE(131);
      if (lookahead == '(') ADVANCE(105);
      if (lookahead == ')') ADVANCE(106);
      if (lookahead == '*') ADVANCE(129);
      if (lookahead == '+') ADVANCE(127);
      if (lookahead == ',') ADVANCE(103);
      if (lookahead == '-') ADVANCE(128);
      if (lookahead == '.') ADVANCE(94);
      if (lookahead == '/') ADVANCE(92);
      if (lookahead == '0') ADVANCE(12);
      if (lookahead == ':') ADVANCE(80);
      if (lookahead == '<') ADVANCE(136);
      if (lookahead == '=') ADVANCE(81);
      if (lookahead == '>') ADVANCE(135);
      if (lookahead == '@') ADVANCE(113);
      if (lookahead == 'B') ADVANCE(29);
      if (lookahead == 'F') ADVANCE(6);
      if (lookahead == 'I') ADVANCE(38);
      if (lookahead == 'L') ADVANCE(28);
      if (lookahead == 'N') ADVANCE(46);
      if (lookahead == 'O') ADVANCE(49);
      if (lookahead == 'S') ADVANCE(64);
      if (lookahead == 'T') ADVANCE(50);
      if (lookahead == '[') ADVANCE(102);
      if (lookahead == '\\') ADVANCE(77);
      if (lookahead == ']') ADVANCE(104);
      if (lookahead == '_') ADVANCE(140);
      if (lookahead == '`') ADVANCE(109);
      if (lookahead == 'a') ADVANCE(57);
      if (lookahead == 'e') ADVANCE(40);
      if (lookahead == 'm') ADVANCE(8);
      if (lookahead == 'r') ADVANCE(21);
      if (lookahead == 't') ADVANCE(27);
      if (lookahead == 'w') ADVANCE(26);
      if (lookahead == '{') ADVANCE(107);
      if (lookahead == '|') ADVANCE(132);
      if (lookahead == '}') ADVANCE(108);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(91);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(91);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(89);
      if (lookahead == '/') ADVANCE(83);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 4:
      if (lookahead == '[') ADVANCE(76);
      END_STATE();
    case 5:
      if (lookahead == ']') ADVANCE(101);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(76);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(33);
      if (lookahead == 'l') ADVANCE(48);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(32);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(51);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(37);
      END_STATE();
    case 12:
      if (lookahead == 'b') ADVANCE(73);
      if (lookahead == 'x') ADVANCE(74);
      END_STATE();
    case 13:
      if (lookahead == 'c') ADVANCE(25);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(79);
      END_STATE();
    case 16:
      if (lookahead == 'e') ADVANCE(97);
      END_STATE();
    case 17:
      if (lookahead == 'e') ADVANCE(98);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 23:
      if (lookahead == 'g') ADVANCE(118);
      END_STATE();
    case 24:
      if (lookahead == 'g') ADVANCE(22);
      END_STATE();
    case 25:
      if (lookahead == 'h') ADVANCE(139);
      END_STATE();
    case 26:
      if (lookahead == 'h') ADVANCE(20);
      END_STATE();
    case 27:
      if (lookahead == 'h') ADVANCE(54);
      END_STATE();
    case 28:
      if (lookahead == 'i') ADVANCE(58);
      END_STATE();
    case 29:
      if (lookahead == 'i') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(45);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(41);
      END_STATE();
    case 31:
      if (lookahead == 'i') ADVANCE(47);
      END_STATE();
    case 32:
      if (lookahead == 'l') ADVANCE(122);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(59);
      END_STATE();
    case 34:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 35:
      if (lookahead == 'm') ADVANCE(115);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(123);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(119);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(65);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(9);
      END_STATE();
    case 40:
      if (lookahead == 'n') ADVANCE(67);
      END_STATE();
    case 41:
      if (lookahead == 'n') ADVANCE(23);
      END_STATE();
    case 42:
      if (lookahead == 'n') ADVANCE(7);
      END_STATE();
    case 43:
      if (lookahead == 'n') ADVANCE(15);
      END_STATE();
    case 44:
      if (lookahead == 'o') ADVANCE(70);
      END_STATE();
    case 45:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 46:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 47:
      if (lookahead == 'o') ADVANCE(42);
      END_STATE();
    case 48:
      if (lookahead == 'o') ADVANCE(10);
      END_STATE();
    case 49:
      if (lookahead == 'p') ADVANCE(63);
      END_STATE();
    case 50:
      if (lookahead == 'r') ADVANCE(68);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(71);
      END_STATE();
    case 52:
      if (lookahead == 'r') ADVANCE(116);
      END_STATE();
    case 53:
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(44);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 56:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 57:
      if (lookahead == 's') ADVANCE(93);
      END_STATE();
    case 58:
      if (lookahead == 's') ADVANCE(61);
      END_STATE();
    case 59:
      if (lookahead == 's') ADVANCE(17);
      END_STATE();
    case 60:
      if (lookahead == 't') ADVANCE(13);
      END_STATE();
    case 61:
      if (lookahead == 't') ADVANCE(121);
      END_STATE();
    case 62:
      if (lookahead == 't') ADVANCE(117);
      END_STATE();
    case 63:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 64:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 65:
      if (lookahead == 't') ADVANCE(14);
      END_STATE();
    case 66:
      if (lookahead == 't') ADVANCE(69);
      END_STATE();
    case 67:
      if (lookahead == 'u') ADVANCE(35);
      END_STATE();
    case 68:
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 69:
      if (lookahead == 'u') ADVANCE(55);
      END_STATE();
    case 70:
      if (lookahead == 'w') ADVANCE(125);
      END_STATE();
    case 71:
      if (lookahead == 'y') ADVANCE(120);
      END_STATE();
    case 72:
      if (lookahead == '{') ADVANCE(110);
      END_STATE();
    case 73:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(99);
      END_STATE();
    case 74:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(100);
      END_STATE();
    case 75:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(5);
      END_STATE();
    case 76:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 77:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(96);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_None);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(111);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(133);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead == '*') ADVANCE(91);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(87);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '*') ADVANCE(90);
      if (lookahead == '/') ADVANCE(84);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(87);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '/') ADVANCE(85);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(87);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(87);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead == '*') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(2);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(87);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      if (lookahead == '*') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(2);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(88);
      if (lookahead == '/') ADVANCE(82);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_as);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_string_token2);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_True);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_False);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_binary_token1);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_binary_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(100);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_binary_token3);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_DOLLAR_LBRACE);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_where);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_Integer);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_Float);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_String);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_Boolean);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_Binary);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_List);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_Optional);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(134);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_throw);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_PIPE_GT);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '>') ADVANCE(112);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '>') ADVANCE(126);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(137);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(138);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_match);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 86},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {(TSStateId)(-1)},
  [8] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_None] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_as] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym_string_token2] = ACTIONS(1),
    [anon_sym_True] = ACTIONS(1),
    [anon_sym_False] = ACTIONS(1),
    [aux_sym_binary_token1] = ACTIONS(1),
    [aux_sym_binary_token2] = ACTIONS(1),
    [aux_sym_binary_token3] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_DOLLAR_LBRACE] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_where] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_Integer] = ACTIONS(1),
    [anon_sym_Float] = ACTIONS(1),
    [anon_sym_String] = ACTIONS(1),
    [anon_sym_Boolean] = ACTIONS(1),
    [anon_sym_Binary] = ACTIONS(1),
    [anon_sym_List] = ACTIONS(1),
    [anon_sym_Optional] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_throw] = ACTIONS(1),
    [anon_sym_PIPE_GT] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_match] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
  },
  [1] = {
    [sym_optional_value] = STATE(5),
    [sym_comment] = STATE(1),
    [anon_sym_None] = ACTIONS(7),
    [anon_sym_SLASH_SLASH] = ACTIONS(3),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(9), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(11), 1,
      aux_sym_comment_token1,
    ACTIONS(13), 1,
      anon_sym_SLASH_STAR,
    STATE(2), 1,
      sym_comment,
  [13] = 4,
    ACTIONS(9), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(13), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(15), 1,
      aux_sym_comment_token2,
    STATE(3), 1,
      sym_comment,
  [26] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_comment,
  [39] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym_comment,
  [52] = 4,
    ACTIONS(3), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(21), 1,
      anon_sym_SLASH,
    STATE(6), 1,
      sym_comment,
  [65] = 1,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
  [69] = 1,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 13,
  [SMALL_STATE(4)] = 26,
  [SMALL_STATE(5)] = 39,
  [SMALL_STATE(6)] = 52,
  [SMALL_STATE(7)] = 65,
  [SMALL_STATE(8)] = 69,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_optional_value, 1),
  [19] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_blossom(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
