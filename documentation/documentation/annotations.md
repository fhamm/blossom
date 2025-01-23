---
icon: percent
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

# Annotations

Annotations in Blossom provide metadata that instructs the compiler to perform specific actions or apply certain rules during compilation. They offer a powerful way to control the compilation process and add extra context to your code.

## %module

The %module annotation declares the module to which the current file belongs. Each file in a Blossom project must belong to a module. Modules provide namespacing and control the visibility of entities (functions, types, etc.).

#### **Syntax**

```
%module ModuleName
```

Where `ModuleName` is a literal representing the name of the module. Module names should follow `PascalCase` (e.g., `MyModule`, `DataProcessing`, `UserAuthentication`).

## %import

The `%import` annotation imports a module, making all its _public_ entities (functions, types and constants) available for use in the current module through qualified access (`ModuleName.entity`).

#### **Syntax**

```
%import ModuleName           // Import the module
%import ModuleName as Alias  // Import the module with an alias
```

Where `ModuleName` is a literal representing the name of the module (which must follow `PascalCase`).

#### **Example**

```
%module MainApp

%import Math              // Import Math module
%import DataUtils as Data // Import with alias

Main -> {
    // Only public members can be accessed
    result1: Integer = Math.Add(5, 3)
    result2: Integer = Math.Subtract(10, 4)
    result3: String = Data.FormatData("test")

    // Attempting to access private members will result
    // in a compile-time error
    // Math._privateFunction()  // Error!

    "{result1}, {result2}, {result3}"
}
```
The compiler will perform dead code elimination to remove any unused entities during compilation, ensuring that only the necessary code is included in the final output.

> **Note**: The visibility of module members is controlled by their declarations within the module. Private members cannot be accessed from outside the module, regardless of how the module is imported.

## %using

The `%using` annotation makes specific public functions or entire modules available in the current scope without requiring module name prefixes. Only public functions and types can be imported - private module members cannot be accessed through `%using`.

#### **Single Import Syntax**

To import a single public function:
```
%using Math.SquareRoot
```

#### **Multiple Import Syntax**

To import multiple public functions from the same module:
```
// Inline with commas
%using Math.[SquareRoot, Sine, Cosine]

// Multiple lines
%using Math.[
    SquareRoot
    Sine
    Cosine
]
```

#### **Example**

```
%module Calculator

%using Math.Sine               // Single function import
%using Math.[Cosine, Tangent]  // Multiple inline imports
%using IO.[
    PrintLine                  // Multiple line-separated
    ReadLine                   // imports for better
    LogError                   // readability
]

Add :: (x: Integer, y: Integer) : Integer -> {
    Sine(x) + Cosine(y)  // Can use functions directly without module prefix
}
```

> **Note**: Attempting to use private module members will result in a compile-time error.

## %public

The `%public` annotation marks all entities (functions, types, constants) in the current module as public. This is useful for modules that are designed to be entirely public-facing, avoiding the need to prefix each declaration with `+`.

#### **Example**

Instead of:
```blossom
%module Math

+PI := 3.14159
+E := 2.71828

+Add :: (x: Float, y: Float) : Float -> x + y
+Subtract :: (x: Float, y: Float) : Float -> x - y
+Multiply :: (x: Float, y: Float) : Float -> x * y
+Divide :: (x: Float, y: Float) : Float ! @DivisionByZero -> {
    match y -> {
        0 -> throw @DivisionByZero
        _ -> x / y
    }
}

+Point := (Float, Float)
+Vector := (Float, Float, Float)
```

You can write:
```blossom
%module Math
%public

PI := 3.14159
E := 2.71828

Add :: (x: Float, y: Float) : Float -> x + y
Subtract :: (x: Float, y: Float) : Float -> x - y
Multiply :: (x: Float, y: Float) : Float -> x * y
Divide :: (x: Float, y: Float) : Float ! @DivisionByZero -> {
    match y -> {
        0 -> throw @DivisionByZero
        _ -> x / y
    }
}

Point := (Float, Float)
Vector := (Float, Float, Float)

-InternalHelper :: (x: Float) : Float -> x * 2  // Still private despite %public
```

> **Note**: You can mark specific entities as private by prefixing them with `-` in a public module.
