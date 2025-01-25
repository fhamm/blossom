use super::utils::*;

#[test]
fn test_arithmetic_expressions() {
    let code = r#"
    %module Test
    Calculate :: (x: Int, y: Int) : Int -> {
        (x + y) * 2 - (30 / y) % x
    }
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_pipeline_expressions() {
    let code = r#"
    %module Test
    Process :: (data: String) : Result ! @(NetworkError, ParseError) -> {
        data
        |> Parse
        !> { @ParseError => throw @ParseError }
        |> Transform
        |> Send
        !> {
            @NetworkError => throw @NetworkError,
            @Timeout => Retry()
        }
    }
    "#;
    assert!(parse_success(code));
}

#[test]
fn test_match_expressions() {
    let code = r#"
    %module Test
    Describe :: (x: Int) : String -> {
        match x -> {
            0 => "Zero",
            n if n < 0 => "Negative",
            n if n % 2 == 0 => "Even",
            _ => "Odd"
        }
    }
    "#;
    assert!(parse_success(code));
}
