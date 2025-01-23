---
icon: box
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

# Modules & Visibility

Every Blossom file must belong to a module. Modules provide a way to organize code and control the visibility of functions, types, and constants.

All files belonging to the same module must be under a common parent directory, but you're free to organize subdirectories as you see fit. The only requirement is that files in a module declare their module membership with the same module name:

```
src/
  Math/                    # Math module root
    core/                  # Subdirectory organization is flexible
      vectors.bs           # %module Math
      matrices.bs          # %module Math
    advanced/
      transformations.bs   # %module Math
    operations.bs          # %module Math
  Http/                    # HTTP module root
    internal/
      parsing.bs          # %module HTTP
      validation.bs       # %module HTTP
    client.bs             # %module HTTP
    server.bs             # %module HTTP
  Main.bs                 # %module Main
```

Each file in the module must declare its module membership:

```blossom
%module Math

// Module contents go here
```

## Visibility

Blossom uses explicit visibility modifiers to control access to module members:

### Public Members

Public members are accessible from other modules. They are marked with a `+` prefix:

```blossom
// Public function
+Add :: (x: Int, y: Int) : Int -> x + y

// Public type
+Point := (Float, Float)

// Public constant
+MAX_RETRIES := 3
```

### Private Members

Private members are only accessible within their declaring module. They are marked with a `-` prefix:

```blossom
// Private function
-Calculate :: (x: Int) : Int -> x * 2

// Private type
-InternalState := (String, Bool)

// Private constant
-CACHE_SIZE := 100
```

### Default Visibility

Members without a prefix are private to their module:

```blossom
// Private by default
Helper :: (x: Int) : Int -> x + 1
```

## Public Modules

For modules where most members should be public, use the `%public` annotation:

```blossom
%module API
%public

// Everything in this module is public by default
HTTPClient := {
    Host: String,
    Port: Int
}

Request :: (client: HttpClient) : Response ! @NetworkError -> {
    // Implementation
}

// Can still mark specific members as private
-InternalHelper :: () -> {
    // Implementation
}
```

## Importing & Using

Public members can be imported and used by other modules:

```blossom
%module Calculator
%import Math              // Import entire module
%import Network as Net    // Import with alias

// Import specific functions
%using Math.SquareRoot
%using IO.[PrintLine, ReadLine]

Main -> {
    Math.Add(1, 2)       // Using qualified import
    Net.Connect()        // Using alias
    SquareRoot(4)        // Using direct import
    PrintLine("Hello")   // Using direct import
}
```

## Best Practices

1. Make members private by default.
2. Only expose what other modules need.
3. Group related functionality in the same module.
4. Keep module interfaces minimal and focused.
