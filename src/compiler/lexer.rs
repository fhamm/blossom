use super::common::Location;
use super::token::{Token, TokenWithLocation};
use std::{iter::Peekable, str::Chars};

#[derive(Debug, PartialEq, Clone)]
pub enum LexError {
    InvalidNumber,
    InvalidEscapeSequence,
    UnterminatedString,
    InvalidOperator,
    InvalidCharacter,
}

pub struct Lexer<'a> {
    input: Peekable<Chars<'a>>,
    current: char,
    location: Location,
}

impl<'a> Lexer<'a> {
    pub fn new(input: &'a str) -> Self {
        let mut chars = input.chars().peekable();
        let current = chars.next().unwrap_or('\0');

        Lexer {
            input: chars,
            current,
            location: Location { line: 1, column: 1 },
        }
    }

    fn advance(&mut self) {
        if let Some(ch) = self.input.next() {
            self.current = ch;
            if ch == '\n' {
                self.location.line += 1;
                self.location.column = 1;
            } else {
                self.location.column += 1;
            }
        } else {
            self.current = '\0'
        }
    }

    // fn peek(&mut self) -> char {
    //     self.input.peek().copied().unwrap_or('\0')
    // }

    fn skip_whitespace(&mut self) {
        while self.current.is_whitespace() && self.current != '\n' {
            self.advance();
        }
    }

    fn read_identifier(&mut self) -> String {
        let mut identifier = String::new();

        while self.current.is_alphanumeric() || self.current == '_' {
            identifier.push(self.current);
            self.advance();
        }

        identifier
    }

    fn read_number(&mut self) -> Token {
        let mut number = String::new();
        let mut is_float = false;

        while self.current.is_digit(10) || self.current == '.' {
            if self.current == '.' {
                if is_float {
                    return Token::Error(
                        "Invalid number format: multiple decimal points".to_string(),
                    );
                }
                is_float = true;
            }
            number.push(self.current);
            self.advance();
        }

        if is_float {
            Token::FloatLiteral(number)
        } else {
            Token::IntegerLiteral(number)
        }
    }

    fn read_string(&mut self) -> Token {
        let mut string = String::new();
        self.advance(); // Skip opening quote

        while self.current != '"' && self.current != '\0' {
            if self.current == '\\' {
                self.advance();
                match self.current {
                    'n' => string.push('\n'),
                    't' => string.push('\t'),
                    'r' => string.push('\r'),
                    '"' => string.push('"'),
                    '\\' => string.push('\\'),
                    _ => return Token::Error("Invalid escape sequence".to_string()),
                }
            } else {
                string.push(self.current);
            }
            self.advance();
        }

        if self.current == '\0' {
            Token::Error("Unterminated string literal".to_string())
        } else {
            self.advance(); // Skip closing quote
            Token::StringLiteral(string)
        }
    }

    pub fn tokenize(&mut self) -> Result<Vec<TokenWithLocation>, LexError> {
        let mut tokens = Vec::new();
        loop {
            match self.next_token()? {
                token if token.token == Token::EOF => break,
                token => tokens.push(token),
            }
        }
        Ok(tokens)
    }

    pub fn next_token(&mut self) -> Result<TokenWithLocation, LexError> {
        self.skip_whitespace();
        let location = Location {
            line: self.location.line,
            column: self.location.column,
        };

        let token = match self.current {
            '\0' => Token::EOF,
            '\n' => {
                self.advance();
                Token::Newline
            }

            '+' => {
                self.advance();
                Token::Plus
            }
            '-' => {
                self.advance();
                if self.current == '>' {
                    self.advance();
                    Token::Arrow
                } else {
                    Token::Minus
                }
            }
            '*' => {
                self.advance();
                Token::Multiply
            }
            '/' => {
                self.advance();
                Token::Divide
            }
            '%' => {
                self.advance();
                Token::Modulo
            }
            '\\' => {
                self.advance();
                Token::Backslash
            }

            '&' => {
                self.advance();
                Token::And
            }
            '|' => {
                self.advance();
                Token::Or
            }
            '!' => {
                self.advance();
                if self.current == '=' {
                    self.advance();
                    Token::NotEquals
                } else {
                    Token::Not
                }
            }
            '=' => {
                self.advance();
                if self.current == '=' {
                    self.advance();
                    Token::Equals
                } else {
                    Token::Error("Expected '=' after '='".to_string())
                }
            }
            '>' => {
                self.advance();
                if self.current == '=' {
                    self.advance();
                    Token::GreaterEquals
                } else {
                    Token::GreaterThan
                }
            }
            '<' => {
                self.advance();
                if self.current == '=' {
                    self.advance();
                    Token::LessEquals
                } else {
                    Token::LessThan
                }
            }

            '(' => {
                self.advance();
                Token::LeftParen
            }
            ')' => {
                self.advance();
                Token::RightParen
            }
            '{' => {
                self.advance();
                if self.current == '{' {
                    self.advance();
                    Token::TemplateStart
                } else {
                    Token::LeftBrace
                }
            }
            '}' => {
                self.advance();
                if self.current == '}' {
                    self.advance();
                    Token::TemplateEnd
                } else {
                    Token::RightBrace
                }
            }
            '[' => {
                self.advance();
                Token::LeftBracket
            }
            ']' => {
                self.advance();
                Token::RightBracket
            }
            ',' => {
                self.advance();
                Token::Comma
            }
            ':' => {
                self.advance();
                Token::Colon
            }

            '"' => self.read_string(),

            c if c.is_digit(10) => self.read_number(),

            c if c.is_alphabetic() || c == '_' => {
                let identifier = self.read_identifier();
                match identifier.as_str() {
                    // Keywords
                    "module" => Token::Module,
                    "public" => Token::Public,
                    "private" => Token::Private,
                    "import" => Token::Import,
                    "match" => Token::Match,
                    "throw" => Token::Throw,

                    // Types
                    "Integer" => Token::Integer,
                    "Float" => Token::Float,
                    "String" => Token::String,
                    "Boolean" => Token::Boolean,
                    "Binary" => Token::Binary,
                    "Nothing" => Token::Nothing,
                    "Optional" => Token::Optional,
                    "List" => Token::List,

                    // Boolean literals
                    "True" => Token::BooleanLiteral(true),
                    "False" => Token::BooleanLiteral(false),

                    // Default to identifier
                    _ => Token::Identifier(identifier),
                }
            }

            _ => {
                self.advance();
                return Err(LexError::InvalidCharacter);
            }
        };

        Ok(TokenWithLocation { token, location })
    }
}
