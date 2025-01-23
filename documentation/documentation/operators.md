---
icon: plus-large
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

# Operators

Operators are a core part of the Blossom language, providing the building blocks for creating expressions, manipulating data and composing functions.

## Arithmetic

These operators perform standard arithmetic calculations.

| Operator | Description        | Example  |
| -------- | ------------------ | -------- |
| `+`      | Addition           | `5 + 3`  |
| `-`      | Subtraction        | `10 - 4` |
| `*`      | Multiplication     | `6 * 7`  |
| `/`      | Division           | `15 / 3` |
| `%`      | Modulo (remainder) | `17 % 5` |

> For more complex operations, use the `Math` module.

## Boolean

These operators perform boolean logic and comparisons.

| Operator | Description         | Example         |
| -------- | ------------------- | --------------- |
| `&`      | Logical AND         | `True & True`   |
| `\|`     | Logical OR          | `True \| False` |
| `!`      | Logical NOT         | `!False`        |
| `==`     | Equality            | `10 == 10`      |
| `!=`     | Inequality          | `5 != 7`        |
| `>`      | Greater than        | `8 > 3`         |
| `<`      | Less than           | `2 < 9`         |
| `>=`     | Greater or equal to | `6 >= 6`        |
| `<=`     | Less or equal to    | `4 <= 5`        |

## Typing & Variables

These operators are used for type/variable declaration and assignment.

<table><thead><tr><th>Operator</th><th width="230">Description</th><th>Example</th></tr></thead><tbody><tr><td><code>:</code></td><td>Type explicitation</td><td><code>name: String</code></td></tr><tr><td><code>=</code></td><td>Value assignment</td><td><code>x: Int = 10</code></td></tr><tr><td><code>:=</code></td><td>Type assignment</td><td><code>FloatList := List(Float)</code></td></tr><tr><td><code>:></code></td><td>Schema assignment</td><td><code>Transformation :> (Int) : Int</code></td></tr><tr><td><code>&#x26;></code></td><td>Type constraint</td><td><code>NonEmptyString := String &#x26;> Constraint&#x3C;v> -> String.NotEmpty(v)</code></td></tr></tbody></table>

## Collections

This section covers operators related to collections (like lists, tuples or records).

<table data-full-width="false"><thead><tr><th>Operator</th><th>Description</th><th>Example</th></tr></thead><tbody><tr><td><code>...</code></td><td>Spread</td><td><code>newList: List(Int) = [...oldList, 4, 5]</code></td></tr></tbody></table>

## Pattern matching

These operators are used for building pattern matching flows.

| Element / Keyword  | Description                                                                               |
| ------------------ | ----------------------------------------------------------------------------------------- |
| `match`            | Begins a pattern matching expression.                                                     |
| `_`                | The wildcard pattern, matches any value. Used as the default case in `match` expressions. |
| `if`               | Used to add conditions to patterns.                                                       |
| `[ head \| tail ]` | Matches the head & tail of a compatible collection type.                                  |

## Pipeline

These operators are used for chaining function calls.

| Operator | Description                                                                                                                |
| -------- | -------------------------------------------------------------------------------------------------------------------------- |
| `\|>`    | **Pipeline operator**. Passes the result of the left-hand expression to the right-hand function.                           |
| `!>`     | **Error-handling pipeline operator**. Executes the following block only if the previous pipeline step results in an error. |
