# Types

Blossom employs a **static**, **strong** and **explicit** typing system with **immutable** variables. Type consistency is asserted during compile time, meaning that any typing mismatch or violation will result in an error, preventing the program from being built.

Besides immutability, **empty** **initializations** **are also** **disallowed**.

## Primitives

The primitive types are the bread & butter of the Blossom typing system.

| Name       | Example(s)                  |
| ---------- | --------------------------- |
| **Bool**   | `True`, `False`             |
| **Int**    | `1517`, `301`, `-127`, `0`  |
| **Float**  | `3.14`, `-1.67`, `1.24e-10` |
| **String** | `"Blossom"`                 |
| **Unit**   | `None`, `Unit`              |

## Atoms & Molecules

Atoms are self-defining values - their identity is their value.
They're immutable, lightweight and perfect for representing unique constants.

```blossom
@Red        // An atom
@Success    // Another atom
@DBError    // And another atom
```

Molecules are groups of related atoms, useful for creating sets of related constants.

```blossom
// Define a molecule of related colors
Colors := @(Red, Green, Blue)

// Define error types
DatabaseError := @(
    ConnectionError,
    AuthenticationError,
    QueryError
)

// Pattern matching with molecules
GetColorName :: (color: Colors) : String -> {
    match color -> {
        Colors.Red   => "Red"
        Colors.Green => "Green"
        Colors.Blue  => "Blue"
    }
}
```

## Collections

Blossom provides several fundamental data structures for organizing and manipulating data.

As with all values in Blossom, collections are **immutable**. Consequently, operations on collections result in the creation of new collections, unlike the in-place modification common in other languages.

### Lists

Lists are homogeneous collections of elements.

```blossom
Numbers: List<Int> = [1, 2, 3, 4, 5]
```

### Sets

Sets are unordered collections of unique values.

```blossom
UniqueColors: Set<String> = {"Red", "Green", "Blue"}
ExtendedColors: Set<String> = Set.Add(UniqueColors, "Yellow")
HasRed: Bool = Set.Contains(UniqueColors, "Red")
```

### Maps

Maps are collections of key-value pairs where each key is unique.

```blossom
Scores: Map<String, Int> = [
    "Alice"   => 95,
    "Bob"     => 87,
    "Charlie" => 92
]
```

### Tuples

Tuples are fixed-size, heterogeneous, ordered collections of values.

```blossom
Point := (Float, Float)
Origin: Point = (0.0, 0.0)
```

### Records

Records are immutable data structures comprised of named fields, each associated with a value.

```blossom
Person := { Name: String, Age: Int }

alice: Person = { Name: "Alice", Age: 30 }
bob: Person = { Name: "Bob", Age: 42 }
```

### Optional

Optional types explicitly handle the presence or absence of a value.

```blossom
FindUser :: (id: String) : Optional<User> -> {
    match Database.Query(id) -> {
        None       => None
        user: User => user
    }
}
```

## Composition

Blossom provides a type composition mechanism, enabling the construction of new types from primitive and collection types. Types are defined using the `:=` operator, a composite symbol representing both type annotation and value assignment.

```blossom
ListOfFloats := List<Float>

Subject := @(Calculus, History, Biology)
Student := { Name: String, Enrollments: List<Course> }
Teacher := { Name: String, Subject: Subject }
Course  := (Teacher, List<Student>)
```

> **Composite types** **must be defined** **outside of function signatures**. This ensures code clarity and promotes type reuse. Type definitions cannot be created inline within function parameters.

## Constraints

Blossom allows you to define runtime constraints on types using the `&>` operator.
Constraints are expressions that must evaluate to a `Bool` value.
Every time a value is assigned to a constrained type, its constraints are validated in order.
If any constraint evaluates to `False`, a `ConstraintError` is thrown.

Constraints are validated in the order they are defined.
**The type name is used within each constraint block to reference the value being validated.**

#### Email
```blossom
Email := String
    &> String.NotEmpty(Email)
    &> String.Length(Email) <= 255
    &> Regex.Validate(Email, EMAIL_REGEX)
```

#### Username
```blossom
Username := String
    &> String.NotEmpty(Username)
    &> String.Length(Username) >= 3
    &> String.Length(Username) <= 20
    &> Regex.OnlyAllows(Username, ~"[a-zA-Z0-9_-]")
```

#### Password
```blossom
Password := String
    &> String.Length(Password) >= 8
    &> String.HasUpperCase(Password)
    &> String.HasLowerCase(Password)
    &> String.HasNumber(Password)
    &> String.HasSpecialChar(Password)
```

#### Rectangle

```blossom
Rectangle := { Width: Float, Height: Float }
    &> Rectangle.Width > 0
    &> Rectangle.Height > 0
    &> Rectangle.Width <= 1000
    &> Rectangle.Height <= 1000
```

#### Generic List
```blossom
NonEmptyList := List<T>
    &> List.Length(NonEmptyList) > 0
    &> List.Length(NonEmptyList) <= 1000
```
