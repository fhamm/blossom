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
| **Bool**    | `True`, `False`             |
| **Int**     | `1517`, `301`, `-127`, `0`  |
| **Float**   | `3.14`, `-1.67`, `1.24e-10` |
| **String**  | `"Blossom"`                 |
| **Unit**    | `None`, `Unit`              |

## Collections

Blossom provides four fundamental data structures for organizing and manipulating data.&#x20;

As with all values in Blossom, collections are **immutable**. Consequently, operations on collections result in the creation of new collections, unlike the in-place modification common in other languages.

### Lists

Lists are homogeneous collections of elements.

#### Syntax

```
Numbers: List<Int> = [1, 2, 3, 4, 5]
```

#### Example

```
Average
  :: (values: List<Float>): Float ! EmptyListError
  ->  {
      match List.Length(values) -> {
        0 -> throw EmptyListError
        length: Int -> {
            sum: Float = List.Fold(values, (acc, n) -> {acc + n}, 0)
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

Enumerations can also be constructed using the spread `...` operator.

```
BaseColors := < Red, Green, Blue >
ExtendedColors := < ...BaseColors, Yellow, Orange, Black, White >
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
Person := { Name: String, Age: Int }
```

#### Example

```
Person := { Name: String, Age: Int }

alice: Person = { Name: "Alice", Age: 30 }
bob: Person = { Name: "Bob", Age: 42 }

UpdateAge(person: Person, newAge: Int): Person -> {
    Log.Info("Updating {{person.Name}}")
    { ...person, Age: newAge }
}
```

## Composition

Blossom provides a type composition mechanism, enabling the construction of new types from primitive and collection types. Types are defined using the `:=` operator, a composite symbol representing both type annotation and value assignment.

#### Syntax

```
ListOfFloats := List<Float>
```

#### Example

```
Subject := < Calculus, History, Biology >
Student := { Name: String, Enrollments: List(Course) }
Teacher := { Name: String, Subject: Subject }
Course  := ( Teacher, List<Student> )
```

> **Composite types** **must be defined** **outside of function signatures**. This ensures code clarity and promotes type reuse. Type definitions cannot be created inline within function parameters.

## Constraints

Blossom allows you to use functions to define type constraints.
That means that every time an assigment is made, the constraint functions are executed and the assigned value is validated.

Type constraints are anonymous functions with the `Constraint` schema.

```
Constraint := t <> t : Bool
```

You can implement them using the `&>` operator.

If, for some reason any of the constraints is violated, a `ConstraintError` is thrown.

#### Example

```
Email
  := String
  &> v -> v != ""
  &> v -> !Regex.Validate(v, EMAIL_REGEX)
```
