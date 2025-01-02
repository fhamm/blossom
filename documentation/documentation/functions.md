---
icon: lambda
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

# Functions

Functions are the fundamental building blocks of Blossom programs. They encapsulate reusable blocks of code, accept arguments, return values, and can explicitly declare the errors they might throw.

## Signatures

A function signature tells you everything you need to know about how to _use_ a function: what inputs it expects, what output it produces, and what errors it might encounter.

Function signatures are composed by:

* **Name:** The function's identifier. This is how you call the function in your code.
* **Parameters (Inputs):** These are the values the function takes as input. Each parameter has a name and a type. If there are no parameters, the function effectively takes no input.
* **Return type (Output):** This is the type of the value the function returns. If the function doesn't explicitly returns anything, its return type is `None`.
* **Error types (Potential errors):** These are the types of errors the function might throw during execution. Listing these errors is a way of saying that the function might not always produce a normal output; it might instead result in an error. This is a way to handle potential side effects.

#### Syntax

<pre><code>// 'HelloWorld' has no arguments, returns nothing and throws no errors.
HelloWorld -> Log.Info("Hello World!")

// 'PrintName' has one argument, returns nothing and throws no errors.
PrintName(name: String) -> { Log.Info("My name is {{ name }}") }
<strong>
</strong><strong>// 'Add' has two arguments, returns an Integer and throws no errors.
</strong><strong>Add(x: Integer, y: Integer): Integer -> { x + y }
</strong>
// 'Divide' has two arguments, returns a Float and 
// possibly throws a 'DivisionByZero' error.
Divide(x: Float, y: Float): Float ! DivisionByZero -> {
    match (x, y) -> {
        (_, 0) -> throw DivisionByZero
        (x, y) -> x / y
    }
}

// 'DivideWithRemainder' takes two Integers and 
// returns a tuple containing the quotient and the remainder.
DivideWithRemainder(dividend: Integer, divisor: Integer): (Integer, Integer) ! DivisionByZero -> {
    match divisor -> {
        0 -> throw DivisionByZero
        _ -> (dividend / divisor, dividend % divisor)
    }
}

// 'CalculateArea' has two arguments, returns a Float and 
// can possibly throw either a 'NegativeSideError' or a 'ZeroAreaError'.
CalculateArea(width: Float, height: Float): Float ! (NegativeSideError, ZeroAreaError) -> {
    match (width, height) -> {
        (w, h) where (w &#x3C; 0 | h &#x3C; 0) -> throw NegativeSideError
        (0, _) -> throw ZeroAreaError
        (_, 0) -> throw ZeroAreaError
        (w, h) -> w * h
  }
}
</code></pre>

## Function Schemas

In Blossom, there are no anonymous functions. We use the concept of scope-based anonymity and function schemas to ensure that we can create functions that only exist in a limited scope while still ensuring rigid typing validation.

Function schemas are defined using the `:>` operator. They are specially useful for functions that receive another function as their argument.

#### Syntax

```
FunctionSchema :> (ParameterType1, ParameterType2, ...): ReturnType ! ErrorType
```

#### Example

```
// Function schema declaration
Transformation :> (Integer): Integer

// 'Map' has a schematized function ('transformation') as one of its arguments
Map(list: List, transformation: Transformation): List(Integer) -> { 
    match list -> { 
        [] -> [] 
        [x, ...xs] -> [transformation(x), ...Map(xs, transformation)] 
    } 
}

// 'ProcessNumbers' calls 'Map' using a local function
ProcessNumbers(numbers: List): List -> { 
    Double(n: Integer): Integer -> { n * 2 } 
    Map(numbers, Double) 
}
```

> **Function schemas** **must be defined** **outside of function signatures**. This ensures code clarity and promotes type reuse. Type definitions cannot be created inline within function parameters.

## Pipelines

The pipeline operator `|>` allows for chaining function calls in a readable left-to-right manner. Each function in the pipeline receives the result of the previous function as its input.

The error handling operator `!>` is used within pipelines to handle errors at each step. It allows for local error handling without breaking the pipeline chain.

#### Example

```
// Without pipeline
updatedUser = UpdateUser(Validate(user))

// With pipeline
updatedUser = user 
    |> Validate
    |> UpdateUser

// Error handling with pipeline
ProcessUser(user: User): ProcessedUser ! (ValidationError, ProcessingError) -> {
    user
    |> Validate !> {
        InvalidData -> throw ValidationError
    }
    |> UpdateUser !> {
        UpdateFailed -> throw ProcessingError
    }
}
```

## Pure Functions

To enable compiler optimizations based on function purity, Blossom provides the `@pure` annotation. Marking a function as `@pure` enables optimizations and static analysis that can improve performance and help catch potential bugs. However, it's crucial that functions marked with `@pure` adhere to specific requirements. Violating these requirements will result in a compiler error.

#### Requirements

A function annotated with `@pure` _must_ satisfy the following conditions:

1. **Referential transparency:** Given the same input arguments, the function _must always_ produce the same output. The function's result should depend _only_ on its input parameters and not on any external state (global variables, mutable data structures, etc.).
2. **No side effects:** The function _must not_ cause any observable changes to the program's state outside of its own scope. This means it _must not_:
   * Modify global variables or mutable data structures passed as arguments.
   * Perform I/O operations (e.g., printing to the console, reading from files, network requests).
   * Throw exceptions or errors (unless those errors are handled internally and do not escape the function).
   * Call other functions that have side effects (unless those functions are also marked `@pure` and correctly adhere to these rules).
3. **Call Tree analysis:** The compiler performs a static analysis of the function's call tree. This means it examines all functions called directly or indirectly from the `@pure` function. _Every function within this call tree must also be `@pure` and adhere to these same requirements._ If the compiler detects a call to a non-`@pure` function within the call tree of a `@pure` function, a compiler error will be issued.

#### Examples

**Correctly** annotated `@pure` functions:

```
@pure 
Add(x: Integer, y: Integer): Integer -> { x + y }

@pure
Multiply(x: Integer, y: Integer): Integer -> { x * y }

@pure
Calculate(x: Integer, y: Integer): Integer -> {
    Add(Multiply(x, x), Multiply(y, y)) // Calls other @pure functions
}
```

In this example, `Add`, `Multiply`, and `Calculate` are all correctly marked as `@pure` because they satisfy all the requirements. `Calculate` depends on `Add` and `Multiply` which are also `@pure`.

**Incorrectly** annotated `@pure` function:

```
@pure
LogAndAdd(x: Integer, y: Integer): Integer -> {
    Log.Info("Adding {{ x }} and {{ y }}")
    x + y
}
```

This example would result in a compiler error because `Log.Info` is assumed to perform I/O (a side effect), violating the "no side effects" requirement.

#### Benefits

* **Compiler optimizations:** The compiler can perform aggressive optimizations, such as constant folding, common subexpression elimination, and memoization on `@pure` functions.
* **Static analysis:** The compiler can perform static analysis to detect potential bugs related to side effects and data dependencies.
* **Improved code clarity:** Marking functions as `@pure` clearly communicates their intended behavior to other developers.

By adhering to these requirements and using the `@pure` annotation correctly, you can leverage Blossom's compiler to write more efficient, reliable and maintainable code.





