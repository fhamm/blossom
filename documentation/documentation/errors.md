---
icon: xmark-large
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

# Errors

Blossom's error handling system combines compile-time checking with runtime safety. It follows two core principles:
1. Errors that can be anticipated must be explicitly declared and handled.
2. Unexpected errors crash the current process, following Erlang's "let it crash" philosophy.

## Signatures

Functions that can fail must declare their potential errors in their signature using the `!` operator.

```blossom
// Single error type
ReadFile :: (path: String) : String ! @FileNotFound

// Multiple error types using a molecule
CreateUser :: (user: User) : UserId ! @(
    InvalidData,
    UserExists,
    DatabaseError
)
```

## Types

### Atoms

For simple error cases, single atoms are sufficient:

```blossom
ValidateEmail :: (email: String) : Bool ! @InvalidEmail
ParseNumber :: (input: String) : Int ! @ParseError
```

### Molecules

For related error types, molecules provide better organization:

```blossom
// Define common database errors
DatabaseError := @(
    ConnectionFailed,
    QueryFailed,
    TransactionFailed,
    DeadLock
)

// Use in function signatures
InsertUser :: (user: User) : UserId ! DatabaseError
```

### Composition

Complex systems often need to combine different error types:

```blossom
// Domain-specific errors
ValidationError := @(
    InvalidEmail,
    InvalidPassword,
    MissingField
)

NetworkError := @(
    Timeout,
    ConnectionLost,
    InvalidResponse
)

// Compose multiple error types
ServiceError := @(
    ...ValidationError,  // Include all ValidationError atoms
    ...NetworkError,     // Include all NetworkError atoms
    InternalError       // Add additional errors
)

// Use composed error type
ProcessRequest :: (req: Request) : Response ! ServiceError
```

## Handling Errors

### Pattern Matching

The primary way to handle errors is through pattern matching:

```blossom
HandleUserCreation :: (userData: UserData) : Response ! @SystemError -> {
    match CreateUser(userData) -> {
        Error(@InvalidData) =>
            Response.BadRequest("Invalid user data")

        Error(@UserExists) =>
            Response.Conflict("User already exists")

        Error(@DatabaseError) =>
            throw @SystemError  // Propagate as different error

        Ok(userId) =>
            Response.Created(userId)
    }
}
```

### Error Propagation

Errors can be propagated up the call stack using `throw`:

```blossom
ProcessOrder :: (order: Order) : OrderId ! @(OrderError, DatabaseError) -> {
    // Validate order
    match ValidateOrder(order) -> {
        Error(e) -> throw e  // Propagate ValidationError
        Ok(validated) -> {
            // Try to save
            match SaveOrder(validated) -> {
                Error(@DatabaseError) => throw @DatabaseError
                Ok(id) => id
            }
        }
    }
}
```

### Pipeline Error Handling

For function chains, the `!>` operator provides elegant error handling:

```blossom
ProcessPayment :: (payment: Payment) : Receipt ! PaymentError -> {
    payment
    |> Validate
    !> { InvalidData => throw @PaymentError }
    |> Authorize
    !> { NotAuthorized => throw @PaymentError }
    |> Process
    !> { ProcessingFailed => throw @PaymentError }
}
```

## Runtime Errors

Some errors cannot or should not be handled:
- Stack overflow
- Out of memory
- Assertion failures
- Unhandled match errors

These follow Erlang's "let it crash" philosophy and are handled by the supervision tree.

## Best Practices

1. **Be specific**: Use specific error types rather than generic ones.
```blossom
// Good
CreateUser :: (user: User) : UserId ! @(InvalidData, UserExists)

// Bad - too generic
CreateUser :: (user: User) : UserId ! @Error
```

2. **Document srrors**: Include error conditions in function documentation.
```blossom
// Calculate percentage with clear error conditions
Percentage :: (
    value: Float,    // The value to convert
    total: Float     // The total to divide by
) : Float ! @(
    NegativeValue,   // When value < 0
    NegativeTotal,   // When total < 0
    ZeroTotal       // When total = 0
)
```

3. **Error granularity**: Balance between too specific and too generic errors.
```blossom
// Too granular
@DatabaseConnectionTimeout
@DatabaseConnectionRefused
@DatabaseHostUnreachable

// Better
DatabaseError := @(
    ConnectionFailed,  // Covers all connection issues
    QueryFailed,
    TransactionFailed
)
```

4. **Consistent error handling**: Handle similar errors consistently throughout your codebase.
```blossom
// Consistent error handling pattern
HandleRequest :: (req: Request) : Response ! @SystemError -> {
    match ProcessRequest(req) -> {
        Error(e)   => LogError(e) |> MapToResponse
        Ok(result) => Response.Ok(result)
    }
}
```
