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

Error handling in Blossom is explicit and type-safe, using atoms and molecules to represent errors. Functions must declare which errors they might raise, and callers must handle these errors appropriately.

## Error Definition

Errors can be defined in three ways:

### Single Atom

For functions that can only raise one type of error, use a single atom:

```blossom
ValidateEmail :: (email: String) : Bool ! @InvalidEmail

ParseNumber :: (input: String) : Int ! @ParseError

ReadFile :: (path: String) : String ! @FileNotFound
```

### Inline Molecule

For functions with a moderate number of related errors, define them inline:

```blossom
CreateUser :: (user: User) : UserId ! @(
    InvalidData,
    UserExists,
    DatabaseError
)

ProcessPayment :: (payment: Payment) : TransactionId ! @(
    InsufficientFunds,
    CardDeclined,
    NetworkError
)
```

### Named Molecule

For complex error sets that might be reused across multiple functions, define a named molecule:

```blossom
DatabaseError := @(
    ConnectionFailed,
    QueryFailed,
    TransactionFailed,
    DeadLock
)

ValidationError := @(
    InvalidEmail,
    InvalidPassword,
    InvalidUsername,
    MissingField
)

// Using named molecules in function signatures
InsertUser :: (user: User) : UserId ! DatabaseError
ValidateUser :: (user: User) : Bool ! ValidationError
```

## Error Handling

Errors must be explicitly handled using pattern matching:

```blossom
HandleUserCreation :: (userData: UserData) : Response ! @SystemError -> {
    match CreateUser(userData) -> {
        Error(@InvalidData) ->
            Response.BadRequest("Invalid user data")

        Error(@UserExists) ->
            Response.Conflict("User already exists")

        Error(@DatabaseError) ->
            throw @SystemError

        Ok(userId) ->
            Response.Created(userId)
    }
}
```

## Error Propagation

Errors can be propagated up the call stack using `throw`:

```blossom
ProcessOrder :: (order: Order) : OrderId ! OrderError -> {
    match ValidateOrder(order) -> {
        Error(e) -> throw e
        Ok(validated) -> CreateOrder(validated)
    }
}
```

## Error Composition

Complex systems might require composing multiple error types:

```blossom
// Define domain-specific errors
OrderError := @(
    InvalidOrder,
    PaymentFailed,
    OutOfStock
)

ShippingError := @(
    InvalidAddress,
    UnsupportedRegion,
    NoCarrier
)

// Compose them into a larger error type
CheckoutError := @(
    ...OrderError,      // Include all OrderError atoms
    ...ShippingError,   // Include all ShippingError atoms
    SessionExpired      // Add additional errors
)

// Use the composed error type
ProcessCheckout
    :: (order: Order, address: Address) : OrderId ! CheckoutError
```

## Best Practices

1. **Be Specific**: Use specific error types rather than generic ones.
```blossom
// Good
CreateUser :: (user: User) : UserId ! @(InvalidData, UserExists)

// Awful!
CreateUser :: (user: User) : UserId ! @Error
```

2. **Group Related Errors**: Use molecules to group related errors.
```blossom
HTTPError := @(
    BadRequest,
    Unauthorized,
    NotFound,
    InternalError
)
```

3. **Error Hierarchies**: Use composition to create error hierarchies.
```blossom
DatabaseError := @(ConnectionError, QueryError)
ValidationError := @(InvalidEmail, InvalidPassword)
ServiceError := @(...DatabaseError, ...ValidationError)
```

4. **Documentation**: Document the specific conditions that cause each error.
```blossom
PaymentError := @(
    InsufficientFunds,  // Balance below transaction amount
    CardExpired,        // Card expiration date in the past
    InvalidCard,        // Card number fails validation
    NetworkError        // Payment gateway unreachable
)
```
```

Would you like me to add or modify anything in this documentation?
