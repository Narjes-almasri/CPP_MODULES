<!-- # CPP_MODULES
Overview
CPP Modules are C++ projects focused on Object-Oriented Programming (OOP). Through them, we learn about namespaces, classes, standard I/O streams, error handling, the Standard Template Library (STL), memory management, and safe type casting. 

## CPP00  
In this module, we learned how to create and use classes, work with namespaces correctly, use streams, and handle errors properly in C++.

## CPP01
In this module, we learned how to perform memory allocation in C++ using new and delete. We also learned about the difference between pointers and references, and how to create pointers to member functions.

## CPP02
In this module, we learned about creating classes in the orthodox canonical style, the use of fixed data types for memory optimization on older computers, ad-hoc polymorphism, and method overloading.

## CPP03
In this module, we learned about inheritance by creating derived classes that inherit members of a base class. -->

# CPP Modules

CPP Modules are a series of C++ projects focused on learning **Object-Oriented Programming (OOP)** concepts.  
Through these modules, we explore namespaces, classes, standard input/output streams, error handling, the Standard Template Library (STL), memory management, and safe type casting.

---

## Table of Contents

- [What is C++?](#what-is-c)
- [Basic Input and Output in C++](#basic-input-and-output-in-c)
  - [`cout` – Standard Output](#cout--standard-output)
  - [`cin` – Standard Input](#cin--standard-input)
  - [`<<` and `>>` Operators](#-and--operators)
- [CPP Modules Overview](#cpp-modules-overview)
  - [CPP00](#cpp00)
  - [CPP01](#cpp01)
  - [CPP02](#cpp02)
  - [CPP03](#cpp03)

---

## What is C++?

C++ is a **high-level, general-purpose programming language** developed by **Bjarne Stroustrup** in the early 1980s at **Bell Labs** as an extension of the C programming language.

### Key Features

- High performance and efficiency  
- Low-level memory control  
- Support for procedural, object-oriented, and generic programming  

### Common Uses

- System and software development  
- Game engines  
- Embedded systems  
- High-performance applications  

**Resources:**  
[Stroustrup on C++](https://www.stroustrup.com/C++.html) | [cppreference.com](https://en.cppreference.com/w/cpp) | [ISO C++](https://isocpp.org)

---

## Basic Input and Output in C++

C++ provides a **type-safe and extensible I/O system** through streams (`<iostream>`), which is different from C's `printf()` and `scanf()` functions.

### `cout` – Standard Output

`cout` is an object of type `std::ostream` that represents the **standard output stream** (usually the terminal).
```cpp
#include <iostream>

int main() {
    std::cout << "Hello World" << std::endl;
    return 0;
}
```

### `cin` – Standard Input

`cin` is an object of type `std::istream` that represents the **standard input stream** (usually keyboard input).
```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;
    return 0;
}
```

**How `cin` works:**
- Reads characters from the input stream
- Converts them into the requested data type
- Stores the result in the provided variable

**Reference:** [cppreference - cin](https://en.cppreference.com/w/cpp/io/cin)

### `<<` and `>>` Operators

- `<<` is the **insertion operator** used with output streams (`cout`)
- `>>` is the **extraction operator** used with input streams (`cin`)

These operators are overloaded functions.

**Example:**
```cpp
std::cout << "Hello, " << name << std::endl;
```

is equivalent to:
```cpp
operator<<(operator<<(std::cout, "Hello, "), name);
```

**Benefits:**
- Supports chaining multiple operations
- Works with user-defined types through operator overloading

**Reference:** [cppreference - operators](https://en.cppreference.com/w/cpp/language/operators)

---

## CPP Modules Overview

### CPP00

**Fundamentals of OOP in C++**

- Creating and using classes
- Proper use of namespaces
- Standard I/O streams (`cin`, `cout`)
- Basic error handling

### CPP01

**Memory Management**

- Dynamic memory allocation (`new` / `delete`)
- Pointers vs. references
- Pointers to member functions

### CPP02

**Advanced Class Design**

- Orthodox Canonical Form (Rule of Three/Five)
- Fixed data types for memory optimization
- Ad-hoc polymorphism
- Method overloading

### CPP03

**Inheritance**

- Inheritance fundamentals
- Derived classes
- Reusing and extending class behavior

