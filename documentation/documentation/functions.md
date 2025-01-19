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

Functions are the core building blocks of Blossom programs, encapsulating reusable code that accepts arguments, returns values and explicitly declares potential errors.

## Signatures

A function signature tells you everything you need to know about how to _use_ a function: what inputs it expects, what output it produces and what errors it might encounter.

Function signatures are composed by their:

* **Name:** The function's identifier. This is how you call the function in your code.
* **Parameters (Inputs):** These are the values the function takes as input. Each parameter has a name and a type. If there are no parameters, the function effectively takes no input.
* **Return type (Output):** This is the type of the value the function returns. If the function doesn't explicitly returns anything, its return type is `Unit`.
* **Errors (Potential errors):** These are the types of errors the function might throw during execution. Listing these errors is a way of saying that the function might not always produce a normal output; it might instead produce an error. This is a way to handle potential side effects.

#### Syntax

`HelloWorld` has no arguments, returns `Unit` and throws no errors. Functions in this format are
called *procedures*.

```
HelloWorld -> Log.Info("Hello World!")
```

`PrintName` has the `name` (`String`) argument, returns `Unit` and throws no errors.

```
PrintName :: (name: String) -> Log.Info("My name is {{ name }}")
```

`Add` has `(x: Int, y: Int)` as its arguments, returns an `Int` and throws no errors.

```
Add :: (x: Int, y: Int): Int -> x + y
```

`Divide` has `(x: Float, y: Float)` as its arguments, returns a `Float` and throws `DivisionError` errors.

```
Divide
    :: (x: Float, y: Float) : Float ! DivisionError
    -> {
      match (x, y) -> {
        (_, 0) -> throw DivisionByZero
        (x, y) -> x / y
      }
    }
```

> Function signatures can be arranged into multiple lines, as shown in the example above.

`DivideWithRemainder` has `(dividend: Int, divisor: Int)` as its arguments, returns a tuple `(Int, Int)` and throws `DivisionError` errors.

```
DivideWithRemainder
    :: (dividend: Int, divisor: Int) : (Int, Int) ! DivisionError
    -> {
      match divisor -> {
          0 -> throw DivisionByZero
          _ -> (dividend / divisor, dividend % divisor)
      }
    }

```

`CalculateArea` has `(width: Float, height: Float)` as its arguments, returns a `Float` and throws the `NegativeSideError` and the `ZeroAreaError` errors.

```
CalculateArea
    :: (width: Float, height: Float) : Float ! AreaError
    -> {
      match (width, height) -> {
        (w, h) where (w < 0 | h < 0) -> throw NegativeSideError
        (0, _) -> throw ZeroAreaError
        (_, 0) -> throw ZeroAreaError
        (w, h) -> w * h
      }
    }
```

## Pipelines

The pipeline operator `|>` allows for **chaining function calls** in a readable syntax. Each function in the pipeline receives the result of the previous function as its input.

The error handling operator `!>` is used within pipelines to **handle errors at each step**. It allows for local error handling without breaking the pipeline chain.

#### Example

Chaining function calls **without** using the pipeline operator.

```
IncrementAndDouble
  :: (x: Int): Int
  -> { Double(Increment(x)) }
```

Chaining function calls **with** the pipeline operator.

```
IncrementAndDouble
  :: (x: Int): Int
  -> { x |> Increment |> Double }
```

Chaining function calls with the pipeline operator and handling possible errors with the pipeline error operator.

```
ProcessUser
    :: (user: User) : ProcessedUser ! ProcessingError
    -> {
      user
      |> Validate
      !> { InvalidData -> throw ValidationError }
      |> UpdateUser
      !> { UpdateFailed -> throw ProcessingError }
    }
```

## Templating

Blossom's philosophy values explicit and self-documented code.
However, there are scenarios where we want to write functions that can operate on different types while maintaining type safety.
Templating provides a way to write generic functions without sacrificing strict typing or code clarity.

Type templating uses the `<>` operator to declare type parameters that can be rendered to concrete types when the code is compiled.

Given that all the types are evaluated during compilation, a compilation error will be thrown if:
1. The template is violated;
2. The rendered types are incompatible with the implementation.

#### Example
```
Add :: t <> (x: t, y: t) : t -> x + y
```

> *The function `Add` has a type parameter `t` and takes two parameters `x` and `y`, both of type `t`, returns a value of type `t`, and its implementation adds `x` and `y`*.


The following examples illustrate how type templating resolves different scenarios during compilation:

---

```blossom
Add(1, 1)        // 2
```

**Valid** because:
1. ✅ Both arguments are integers (`Int`), so `t` resolves to `Int`;
2. ✅ The `+` operator is defined for the `Int` type, and thus compatible with the implementation.

---

```blossom
Add(0.5, 0.5)    // 1.0
```

**Valid** because:
1. ✅ Both arguments are floating-point numbers (`Float`), so `t` resolves to `Float`;
2. ✅ The `+` operator is defined for the `Float` type, and thus compatible with the implementation.

---

```blossom
Add(None, None)  // TemplateError
```

**Invalid** because:
1. ✅ Both arguments are `None`, so `t` resolves to `None`;
2. 🚫 The `+` operator is not defined for the `None` type, making the implementation incompatible with the rendered type.

---

```blossom
Add(1, 0.5)      // TemplateError
```

**Invalid** because:
1. 🚫 Arguments have different types (`Int` and `Float`), which violates the template;
2. 🚫 The `+` operator is not compatible with different types.

## Schemas

Function schemas allow the creation of function templates within Blossom, promoting reusability
with type safety. Function schemas are defined using the `:>` operator.

#### Example
```
Adder :> (Int, Int) : Int

Add :: Adder<x, y> -> x + y
```

Schemas also enable the definition of anonymous functions within blossom.

## Higher-order functions & Anonymous functions

Conceptually, a higher-order function is a function that does at least one of the following:
* Takes one or more functions as parameters;
* Returns a function as its result.

Higher-order functions often work in conjunction with anonymous functions - functions
with a temporary lifespan that are defined inline where they're used.

A classic example is the `Map` function, which takes a transformation
function as a parameter to process each element in a list:

#### Example

```
Mapper := t <> t : t

Map
  :: t <> (list: List<t>, fn: Mapper<t>) : List<t>
  -> {
    match list -> {
        [] -> []
        [x, ...xs] -> [fn(x), ...Map(xs, fn)]
    }
  }

DoubleNumbers
  :: (numbers: List<Int>) : List<Int>
  -> Map(numbers, Mapper<n> -> n * 2 )
```

In Blossom, anonymous functions must be defined using a schema (like `Mapper<Int>` above). This explicit typing serves two purposes:
1. Makes the function's contract immediately visible;
2. Helps developers understand the purpose of the anonymous function without checking the parent function's signature

> **Note**: Function schemas, like composite types, must be defined outside of function signatures. This ensures code clarity and promotes type reuse. Type definitions cannot be created inline within function parameters.

## Pure Functions

Blossom's compiler automatically detects pure functions and applies optimizations accordingly.
A function is considered pure if it satisfies specific requirements, enabling the compiler to perform various optimizations and static analysis.

#### Requirements for Purity

The compiler considers a function pure when it satisfies these conditions:

1. **Referential transparency:** Given the same input arguments, the function must always produce the same output. The function's result should depend only on its input parameters.

2. **No side effects:** The function must not cause any observable changes to the program's state outside of its own scope. This means it must not:
   * Modify global variables or mutable data structures
   * Perform I/O operations
   * Throw unhandled exceptions
   * Call functions that have side effects

#### Examples

**Pure** functions:
```blossom
Add(x: Int, y: Int): Int -> x + y

Multiply(x: Int, y: Int): Int -> x * y

Calculate(x: Int, y: Int): Int -> {
    Add(Multiply(x, x), Multiply(y, y))
}
```

These functions are automatically detected as pure because they only depend on their inputs and have no side effects.

**Impure** function:
```blossom
LogAndAdd(x: Int, y: Int): Int -> {
    Log.Info("Adding {{ x }} and {{ y }}")
    x + y
}
```

This function is detected as impure because it performs I/O through `Log.Info`.

#### Benefits

When the compiler identifies a function as pure, it automatically enables:
* Memoization
* Constant folding
* Common subexpression elimination
* Other optimizations specific to pure functions

These optimizations happen automatically without requiring explicit annotations, making the
code cleaner while maintaining all the benefits of pure function optimization.
