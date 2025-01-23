---
icon: shuffle
layout:
  title:
    visible: true
  description:
    visible: false
  tableOfContents:
    visible: true
  outline:
    visible: true
  pagination:
    visible: true
---

# Flow

Blossom provides powerful pattern matching mechanisms for control flow. Being an immutable language, control flow in Blossom focuses on expressions that return values rather than statements that modify state.

## Pattern Matching

Pattern matching is the primary mechanism for control flow in Blossom. The `match` expression allows you to destructure values and execute different code based on patterns.

### Basic Matching

```blossom
GetDiscountRate :: (age: Int) : Float -> {
    match age -> {
        0      => 0.0
        1..17  => 0.25
        18..65 => 0.0
        _      => 0.15
    }
}
```

### Destructuring

```blossom
+Point := (Float, Float)

DescribePoint :: (p: Point) : String -> {
    match p -> {
        (0, 0) => "At origin"
        (x, 0) => "On X axis at {x}"
        (0, y) => "On Y axis at {y}"
        (x, y) => "At ({x}, {y})"
    }
}
```

### Guards

Pattern matching can include guard conditions using `if`:

```blossom
Classify :: (n: Int) : String -> {
    match n -> {
        n if n < 0      => "Negative"
        n if n == 0     => "Zero"
        n if n % 2 == 0 => "Positive Even"
        _               => "Positive Odd"
    }
}
```

### Multiple Patterns

You can match multiple patterns to the same result using `|`:

```blossom
IsWeekend :: (day: String) : Bool -> {
    match day -> {
        "Saturday" | "Sunday" => True
        _ => False
    }
}
```

## Loops

Being a functional language, Blossom handles repetition through recursion and higher-order functions rather than traditional loops.

### List Processing

```blossom
// Using map for transformation
Double :: (numbers: List<Int>) : List<Int> -> {
    List.Map(numbers, Mapper<n> -> n * 2)
}

// Using fold for accumulation
Sum :: (numbers: List<Int>) : Int -> {
    List.Fold(numbers, 0, Folder<acc, n> -> acc + n)
}
```

### Recursion

For cases requiring custom iteration logic, use recursion:

```blossom
Factorial :: (n: Int) : Int ! @NegativeInput -> {
    match n -> {
        n if n < 0 => throw @NegativeInput
        0          => 1
        n          => n * Factorial(n - 1)
    }
}
```

## Error Flow

Error handling is part of the control flow in Blossom. Errors must be explicitly handled or propagated:

```blossom
ProcessUser :: (user: User) : Result ! @(ValidationError, DatabaseError) -> {
    match ValidateUser(user) -> {
        Error(@InvalidData) =>
            throw @ValidationError

        Error(@SystemError) =>
            throw @ValidationError

        Ok(validated) => {
            match SaveUser(validated) => {
                Error(e) => throw @DatabaseError
                Ok(result) => result
            }
        }
    }
}
```

## Best Practices

1. Use pattern matching as the primary control flow mechanism
2. Use guards (`if`) to make pattern matching conditions clear
3. Keep pattern matching cases exhaustive
4. Use higher-order functions instead of explicit recursion when possible
5. Handle all error cases explicitly
