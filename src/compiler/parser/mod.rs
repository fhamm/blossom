use pest::{iterators::Pairs, Parser};
use pest_derive::Parser;

#[cfg(test)]
mod tests;

#[derive(Parser)]
#[grammar = "parser/grammar/blossom.pest"]
struct BlossomParser;

pub fn parse(input: &str) -> Result<Pairs<Rule>, pest::error::Error<Rule>> {
    BlossomParser::parse(Rule::BLOSSOM, input)
}
