use super::common::Location;

#[derive(Debug, PartialEq, Clone)]
pub enum Token {
    // Annotations
    Module,  // @Module
    Public,  // @Public
    Private, // @Private
    Import,  // @Import
    Pure,    // @Pure
    Impure,  // @Impure

    // Keywords
    Match, // match
    Throw, // throw

    // Types
    Integer,
    Float,
    String,
    Boolean,
    Binary,
    Nothing,
    Optional,
    List,

    // Literals
    IntegerLiteral(String),
    FloatLiteral(String),
    StringLiteral(String),
    BooleanLiteral(bool),
    BinaryLiteral(Vec<u8>),

    // Identifiers
    Identifier(String),

    // Arithmetic operators
    Plus,     // +
    Minus,    // -
    Multiply, // *
    Divide,   // /
    Modulo,   // %

    // Boolean operators
    And,           // &
    Or,            // |
    Not,           // !
    Equals,        // ==
    NotEquals,     // !=
    GreaterThan,   // >
    LessThan,      // <
    GreaterEquals, // >=
    LessEquals,    // <=

    // Functional operators
    Arrow,  // ->
    Spread, // ...
    Pipe,   // |>

    // Delimiters
    LeftParen,    // (
    RightParen,   // )
    LeftBrace,    // {
    RightBrace,   // }
    LeftBracket,  // [
    RightBracket, // ]
    Comma,        // ,
    Colon,        // :
    Backslash,    // \

    // Template
    TemplateStart, // {{
    TemplateEnd,   // }}

    // Special
    Newline,
    EOF,
    Error(String),
}

// pub struct Token {
//     pub kind: TokenKind,
//     pub lexeme: String,
// }

#[derive(Debug, PartialEq, Clone)]
pub struct TokenWithLocation {
    pub token: Token,
    pub location: Location,
}
