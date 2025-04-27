
# Assignment 2 - Square Matrix Class Implementation (SquareMat)

**Name:** Leon Pasternak 
**Email:** leonandsani@gmail.com

---

## Project Overview

This project implements the `SquareMat` class, representing square matrices of real numbers, with extensive operator overloading support.

- Mathematical operations: addition, subtraction, matrix multiplication, scalar multiplication, division, modulo, exponentiation.
- Special operators: transpose (`~`), determinant (`!`), unary minus (`-`), increment (`++`), decrement (`--`).
- Comparison operators based on the sum of all matrix elements.
- Access to matrix elements using the `[]` operator.
- Unit tests (`Test.cpp`) written using the `doctest` library.
- Proper memory management: implementing the Rule of Three (copy constructor, assignment operator, destructor).
- Verified memory leak-free operation using `valgrind`.

---

## Project Structure

```plaintext
/
├── SquareMat.hpp     // Class declarations
├── SquareMat.cpp     // Class implementation
├── Main.cpp          // Demo file
├── Test.cpp          // Unit tests with doctest
├── doctest.h         // Testing library 
├── Makefile          // Compilation and execution commands
└── README.md         // This explanation file
```

---
