use super::utils::*;

#[test]
fn test_numeric_constants() {
    let code = r#"
    %module Test
    PI : Float = 3.14159
    MAX_COUNT : Int = 100
    NEGATIVE : Int = -42
    SCIENTIFIC : Float = 1.23e-10
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_string_constants() {
    let code = r#"
    %module Test
    NAME : String = "Blossom"
    EMPTY : String = ""
    TEMPLATE : String = "Hello, {NAME}!"
    MULTILINE : String = "This is a
        multiline string"
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_boolean_constants() {
    let code = r#"
    %module Test
    ENABLED : Bool = True
    DEBUG : Bool = False
    "#;
    assert!(parse_success(code));
}
