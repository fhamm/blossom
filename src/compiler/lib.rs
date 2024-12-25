use blossom_config::BlossomConfig;
use lexer::Lexer;

pub mod common;
pub mod lexer;
pub mod token;
// pub mod parser;

pub fn compile(config: &BlossomConfig) {
    let mut lexer = Lexer::new("blabla");
    let tokens = lexer.tokenize();

    print!("{:?}", tokens);
}
