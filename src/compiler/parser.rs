use pest::{iterators::Pairs, Parser};
use pest_derive::Parser;

#[derive(Parser)]
#[grammar = "blossom.pest"]
struct BlossomParser;

pub fn parse(input: &str) -> Result<Pairs<Rule>, pest::error::Error<Rule>> {
    BlossomParser::parse(Rule::BLOSSOM, input)
}
