use super::utils::*;

#[test]
fn test_primitive_type() {
    let code = r#"
    %module Test
    Age := Int
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_compound_types() {
    let code = r#"
    %module Test
    Point := (Float, Float)
    User := { name: String, age: Int }
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_constrained_types() {
    let code = r#"
    %module Test
    Email := String
        &> String.Contains(Email, "@")
        &> String.Contains(Email, ".")
    "#;
    assert!(parse_success(code));
}
