---
icon: at
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

## @module

The @module annotation declares the module to which the current file belongs. Each file in a Blossom project must belong to a module. Modules provide namespacing and control the visibility of entities (functions, types, etc.).

#### **Syntax**

```
@module ModuleName
```

Where `ModuleName` is a literal representing the name of the module. Module names should follow `PascalCase` (e.g., `MyModule`, `DataProcessing`, `UserAuthentication`).

## @import

The `@import` annotation imports an entire module, making all its _public_ entities (functions, types, etc.) available for use in the current module. The compiler will perform dead code elimination to remove any unused entities during compilation, ensuring that only the necessary code is included in the final output. This simplifies the import process and improves code maintainability. Aliasing is supported, allowing you to use a different name for the imported module in the current module.

#### **Syntax**

```
@import ModuleName           // Import the module
@import ModuleName as Alias  // Import the module with an alias
```

Where `ModuleName` is a literal representing the name of the module (which must follow `PascalCase`).

#### **Example**

```
@module MainApp

@import MyMath
@import DataUtils as Data

Main(): String -> {
    result1: Integer = MyMath.Add(5, 3)            // Accessing a function from MyMath
    result2: Integer = MyMath.Subtract(10, 4)      // Accessing another function from MyMath
    result3: String = Data.FormatData("some data") // Accessing a function from DataUtils via alias
    "{{result1}}, {{result2}}, {{result3}}"
}
```

## @using

The `@using` annotation imports a module and makes its public entities available in the current scope without requiring module name prefixes.

#### **Example**

```
@module Calculator
@using Math

Add(x: Integer, y: Integer): Integer -> {
    Sin(x) + Cos(y)  // Can use Sin instead of Math.Sin
}
```

## @pure

The `@pure` annotation tags a function to be compiled as a [_pure function_](functions.md#pure-functions).

#### Example

```
@pure 
Add(x: Integer, y: Integer): Integer -> { x + y }
```

