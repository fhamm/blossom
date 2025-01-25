use super::utils::*;

#[test]
fn test_tuple_patterns() {
    let code = r#"
    %module Test
    HandlePoint :: (p: Point) : String -> {
        match p -> {
            (0, 0) => "At origin",
            (x, 0) => "On X axis at {x}",
            (0, y) => "On Y axis at {y}",
            (x, y) => "At ({x}, {y})"
        }
    }
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_list_patterns() {
    let code = r#"
    %module Test
    Describe :: (list: List<Int>) : String -> {
        match list -> {
            [] => "Empty list",
            [x] => "Single element: {x}",
            [x, y] => "Two elements: {x} and {y}",
            [x, ...rest] => "More than two elements",
            _ => "Something else"
        }
    }
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_record_patterns() {
    let code = r#"
    %module Test
    HandleUser :: (user: User) : String -> {
        match user -> {
            { name: "Admin", _ } => "Welcome, admin!",
            { name: n, age: a } if a < 18 => "Hello, young {n}!",
            { name: n, status: @Active } => "Welcome back, {n}!",
            { name: n, status: @Banned } => "Account {n} is banned",
            _ => "Hello, guest!"
        }
    }
    "#;
    assert!(parse_success(code));
}
