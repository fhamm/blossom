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
2. ✅ The `+` operator is defined for the `Int` type, and thus compatible with the implementation;

---

```blossom
Add(0.5, 0.5)    // 1.0
```

**Valid** because:
1. ✅ Both arguments are floating-point numbers (`Float`), so `t` resolves to `Float`;
2. ✅ The `+` operator is defined for the `Float` type, and thus compatible with the implementation;

---

```blossom
Add(None, None)  // TemplateError
```

**Invalid** because:
1. ✅ Both arguments are `None`, so `t` resolves to `None`;
2. 🚫 The `+` operator is not defined for the `None` type, making the implementation incompatible with the rendered type;

---

```blossom
Add(1, 0.5)      // TemplateError
```

**Invalid** because:
1. 🚫 Arguments have different types (`Int` and `Float`), which violates the template;
2. 🚫 The `+` operator is not compatible with different types;

## Schemas

Function schemas are


## Higher-order functions

Conceptually, a higher-order function is a function that does at least one of the following:
* Takes one or more functions as parameters;
* Returns a function as its result.

A classical example of a higher-order function is the `Map` function, which receives a function
as one of its parameters in order to recursively map the values in a list.

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

DoubleNumbers :: (numbers: List<Int>) : List<Int> -> Map(numbers, n -> n * 2 )
```


> **Function schemas** **must be defined** **outside of function signatures**. This ensures code clarity and promotes type reuse. Type definitions cannot be created inline within function parameters.


## Pure Functions (deprecated, optimization is automatic)

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
Add(x: Int, y: Int): Int -> { x + y }

@pure
Multiply(x: Int, y: Int): Int -> { x * y }

@pure
Calculate(x: Int, y: Int): Int -> {
    Add(Multiply(x, x), Multiply(y, y)) // Calls other @pure functions
}
```

In this example, `Add`, `Multiply`, and `Calculate` are all correctly marked as `@pure` because they satisfy all the requirements. `Calculate` depends on `Add` and `Multiply` which are also `@pure`.

**Incorrectly** annotated `@pure` function:

```
@pure
LogAndAdd(x: Int, y: Int): Int -> {
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
