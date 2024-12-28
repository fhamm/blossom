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

Besides immutability, Blossom also disallows empty initializations.

### Primitives

| Name        | Example(s)                  |
| ----------- | --------------------------- |
| **Boolean** | `True`                      |
| **Integer** | `1517`, `301`, `-127`, `0`  |
| **Float**   | `3.14`, `-1.67`, `1.24e-10` |
| **String**  | `"Blossom"`                 |
| **None**    | `None`                      |

