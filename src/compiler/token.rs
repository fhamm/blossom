use super::common::Location;

#[derive(Debug, PartialEq, Clone)]
pub enum Token {
    // Existing annotations
    Module,
    Public,
    Private,
    Import,
    Pure,
    Impure,
    Using,
    As,

    // Existing keywords
    Match,
    Throw,

    // Existing types
    Integer,
    Float,
    String,
    Boolean,
    Binary,
    Nothing,
    Optional,
    List,

    // Existing literals
    IntegerLiteral(String),
    FloatLiteral(String),
    StringLiteral(String),
    BooleanLiteral(bool),
    BinaryLiteral(Vec<u8>),

    // Identifiers
    Identifier(String),

    // Arithmetic operators
    Plus,
    Minus,
    Multiply,
    Divide,
    Modulo,

    // Boolean/Type operators
    And,           // & (both logical AND and type constraints)
    Or,            // |
    Not,           // !
    Equals,        // ==
    NotEquals,     // !=
    GreaterThan,   // >
    LessThan,      //
    GreaterEquals, // >=
    LessEquals,    // <=

    // Functional operators
    Arrow,     // ->
    Spread,    // ...
    Pipe,      // |>
    ErrorPipe, // !>

    // Comment delimiters
    CommentStart, // /*
    CommentEnd,   // */

    // Existing delimiters
    LeftParenthesis,
    RightParenthesis,
    LeftBrace,
    RightBrace,
    LeftBracket,
    RightBracket,
    Comma,
    Colon,
    Backslash,

    // Template
    TemplateStart,
    TemplateEnd,

    // Special
    Newline,
    EOF,
    Error(String),
}

#[derive(Debug, PartialEq, Clone)]
pub struct TokenWithLocation {
    pub token: Token,
    pub location: Location,
}
