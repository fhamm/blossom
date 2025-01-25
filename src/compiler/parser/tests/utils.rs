use crate::parser::parse;

pub fn parse_success(input: &str) -> bool {
    parse(input).is_ok()
}

#[allow(dead_code)]
pub fn parse_and_print(input: &str) -> Result<(), String> {
    match parse(input) {
        Ok(_) => Ok(()),
        Err(e) => Err(format!("Parse error: {}", e)),
    }
}
