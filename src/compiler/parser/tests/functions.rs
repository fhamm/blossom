use super::utils::*;

#[test]
fn test_procedure() {
    let code = r#"
    %module Test
    Main -> PrintLine("Hello World!")
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_function_with_signature() {
    let code = r#"
    %module Test
    Add :: (x: Int, y: Int) : Int -> x + y
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_function_with_error_handling() {
    let code = r#"
    %module Test
    Divide :: (a: Int, b: Int) : Int ! @DivisionError -> {
        match (a, b) -> {
            (_, 0) => throw @DivisionError,
            (a, b) => a / b
        }
    }
    "#;
    assert!(parse_success(code));
}
