use super::utils::*;

#[test]
fn test_basic_module() {
    let code = r#"
    %module Test
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_module_with_imports() {
    let code = r#"
    %module Test
    %import IO
    %import Math
    %import Network as Net
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_module_with_using() {
    let code = r#"
    %module Test
    %using Math.Sin
    %using IO.[PrintLine, ReadLine]
    %using Network.[
        Connect,
        Send,
        Receive
    ]
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_public_module() {
    let code = r#"
    %module API
    %public
    "#;
    assert!(parse_success(code));
}
