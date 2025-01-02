---
icon: text
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

# Types

Blossom employs a **static**, **strong** and **explicit** typing system with **immutable** variables. Type consistency is asserted during compile time, meaning that any typing mismatch or violation will result in an error, preventing the program from being built.

Besides immutability, **empty** **initializations** **are also** **disallowed**.

## Primitives

The primitive types are the bread & butter of the Blossom typing system.

| Name        | Example(s)                  |
| ----------- | --------------------------- |
| **Boolean** | `True`                      |
| **Integer** | `1517`, `301`, `-127`, `0`  |
| **Float**   | `3.14`, `-1.67`, `1.24e-10` |
| **String**  | `"Blossom"`                 |
| **None**    | `None`                      |

## Collections

Blossom provides four fundamental data structures for organizing and manipulating data.&#x20;

As with all values in Blossom, collections are **immutable**. Consequently, operations on collections result in the creation of new collections, unlike the in-place modification common in other languages.

### Lists

Lists are homogeneous collections of elements.

#### Syntax

```
Numbers: List(Integer) = [1, 2, 3, 4, 5]
```

#### Example

```
Average(values: List(Float)): Float ! EmptyListError -> {
    match List.Length(values) -> {
        0 -> throw EmptyListError
        length: Integer -> {
            sum: Float = values.Fold((acc: Float, n: Float) -> {acc + n}, 0)
            sum / Float.From(length)
        }
    }
}
```

### Enumerations

Enumerations are grouped, non-valued self-definitions. In contrast to other languages, Blossom enumerations do not carry associated data.

#### Syntax

```
Colors := < Red, Green, Blue >
```

#### Example

```
Direction := < North, South, East, West >

heading: Direction = Direction.North

ProcessDirection(direction: Direction): String -> {
    match direction -> {
        Direction.North -> "Moving North"
        Direction.South -> "Moving South"
        Direction.East -> "Moving East"
        Direction.West -> "Moving West"
    }
}
```

### Tuples

Tuples are fixed-size, heterogeneous, ordered collections of values.

#### Syntax

```
Coordinates := (Float, Float, Float)
```

#### Example

```
Point := (Float, Float)

Origin: Point = (0.0, 0.0)

Distance(p1: Point, p2: Point): Float -> {
    dx: Float = p2[0] - p1[1]
    dy: Float = p2[0] - p1[1]
    Math.SquareRoot(dx * dx + dy * dy) 
}
```

### Records

Records are immutable data structures comprised of named fields, each associated with a value.

#### Syntax

```
Person := { Name: String, Age: Integer }
```

#### Example

```
Person := { Name: String, Age: Integer }

alice: Person = { Name: "Alice", Age: 30 }
bob: Person = { Name: "Bob", Age: 42 }

UpdateAge(person: Person, newAge: Integer): Person -> {
    Log.Info("Updating {{person.Name}}")
    { ...person, Age: newAge }
}
```

## Composition

Blossom provides a type composition mechanism, enabling the construction of new types from primitive and collection types. Types are defined using the `:=` operator, a composite symbol representing both type annotation and value assignment.

#### Syntax

```
ListOfFloats := List(Float)
```

#### Example

```
Subject := < Calculus, History, Biology >
Student := { Name: String, Enrollments: List(Course) }
Teacher := { Name: String, Subject: Subject }
Course  := ( Teacher, List(Student) )
```

> **Composite types** **must be defined** **outside of function signatures**. This ensures code clarity and promotes type reuse. Type definitions cannot be created inline within function parameters.

## Constraints

Constraints, implemented as optimized callbacks to pure functions triggered at runtime during assignment, enable the definition of complex types. Constraint violations raise a `ConstraintError`. Blossom optimizes constraint evaluation via compile-time construction of an internal execution tree.

#### Syntax

```
TypeName := BaseType -> ConstraintExpression
```

#### Example

```
PositiveInteger := Integer -> LargerThan(0)
Age := Integer -> LargerThan(0) & LowerThan(150)
Email := String -> IsEmail
```

You can also add constraints to composite collection types:

```
Fruits := List(String) -> NotEmpty 
Coordinates := (Float, Float, Float) -> LargerThan(0.0)
```
