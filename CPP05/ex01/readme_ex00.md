# C++ Module 05: Exception Handling

## Table of Contents
1. [Exception Handling in C++](#exception-handling-in-c)
2. [Exercise 00: Bureaucrat](#exercise-00-mommy-when-i-grow-up-i-want-to-be-a-bureaucrat)

---

# Exception Handling in C++

## What is Exception Handling?

Exception handling is a mechanism to handle runtime errors in a controlled way, allowing your program to respond to exceptional circumstances (like errors) during execution without crashing.

## Basic Syntax

```cpp
try {
    // Code that might throw an exception
    // risky operations go here
} 
catch (ExceptionType e) {
    // Code to handle the exception
    // recovery or error reporting goes here
}
```

## How It Works

### The Flow

1. **Try Block**: The program attempts to execute the code inside the `try` block
2. **Exception Occurs**: If an error happens, an exception is "thrown"
3. **Catch Block**: The program immediately jumps to the corresponding `catch` block
4. **Handle Exception**: The catch block executes code to handle the error
5. **Continue**: After the catch block, the program continues normally (if possible)

### Visual Flow

```
try {
    statement1;  ✓ executes
    statement2;  ✓ executes
    statement3;  ✗ ERROR! throws exception
    statement4;  ✗ skipped
    statement5;  ✗ skipped
}
catch (...) {
    // Jumps directly here
    handle error;  ✓ executes
}
// Program continues here
```

## Types of Exceptions

### 1. Standard Library Exceptions

C++ provides built-in exception types:

```cpp
#include <stdexcept>
#include <iostream>
using namespace std;

try {
    throw runtime_error("Something went wrong!");
} 
catch (runtime_error& e) {
    cout << "Error: " << e.what() << endl;
}
```

**Common standard exceptions:**
- `runtime_error` - General runtime errors
- `logic_error` - Logic errors in the program
- `out_of_range` - Access out of valid range
- `invalid_argument` - Invalid argument passed
- `bad_alloc` - Memory allocation failed

### 2. Catching Different Exception Types

You can have multiple catch blocks for different exception types:

```cpp
try {
    // risky code
    int age;
    cin >> age;
    
    if (age < 0) {
        throw invalid_argument("Age cannot be negative");
    }
    if (age > 150) {
        throw out_of_range("Age is unrealistically high");
    }
}
catch (invalid_argument& e) {
    cout << "Invalid input: " << e.what() << endl;
}
catch (out_of_range& e) {
    cout << "Range error: " << e.what() << endl;
}
catch (...) {
    // Catch ANY other exception
    cout << "Unknown error occurred" << endl;
}
```

### 3. Throwing Custom Exceptions

You can throw any type, including primitive types or custom classes:

```cpp
// Throwing integers
try {
    int errorCode = -1;
    if (errorCode < 0) {
        throw errorCode;
    }
}
catch (int e) {
    cout << "Error code: " << e << endl;
}

// Throwing strings
try {
    throw string("File not found");
}
catch (string& e) {
    cout << "Error: " << e << endl;
}
```

## When to Use `throw`

### Automatic vs Manual Throwing

**Some functions throw automatically:**
```cpp
#include <vector>

try {
    vector<int> vec = {1, 2, 3};
    cout << vec.at(10);  // Automatically throws out_of_range
}
catch (out_of_range& e) {
    cout << "Error: " << e.what() << endl;
}
```

**You throw manually when:**
```cpp
double divide(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Division by zero!");  // YOU decide this is an error
    }
    return a / b;
}

try {
    double result = divide(10, 0);
}
catch (invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
}
```

## Complete Example

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    double balance;
    
public:
    BankAccount(double initial) : balance(initial) {}
    
    void withdraw(double amount) {
        if (amount < 0) {
            throw invalid_argument("Withdrawal amount cannot be negative");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient funds");
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: $" << balance << endl;
    }
    
    double getBalance() const { return balance; }
};

int main() {
    BankAccount account(100.0);
    
    try {
        account.withdraw(50);   // ✓ Success
        account.withdraw(75);   // ✗ Throws runtime_error
        account.withdraw(10);   // Never reached
    }
    catch (invalid_argument& e) {
        cout << "Invalid operation: " << e.what() << endl;
    }
    catch (runtime_error& e) {
        cout << "Transaction failed: " << e.what() << endl;
    }
    
    cout << "Program continues..." << endl;
    cout << "Final balance: $" << account.getBalance() << endl;
    
    return 0;
}
```

**Output:**
```
Withdrawal successful. New balance: $50
Transaction failed: Insufficient funds
Program continues...
Final balance: $50
```

## Best Practices

1. **Catch by reference** (`catch (exception& e)`) to avoid object slicing
2. **Order catch blocks** from most specific to most general
3. **Always have a catch-all** (`catch (...)`) for unexpected exceptions
4. **Don't throw in destructors** - can cause program termination
5. **Use standard exceptions** when possible instead of custom types
6. **Throw exceptions for exceptional cases** - don't use them for normal control flow

## Key Takeaways

- `try` - "Let me attempt this code"
- `throw` - "Something's wrong, stop execution!" (manual or automatic)
- `catch` - "I'll handle the error"
- **Not all code throws** - you use `throw` to create errors based on YOUR conditions
- **Some functions auto-throw** - like `vector::at()`, `stoi()`, etc.
- **Exceptions jump immediately** to the catch block, skipping remaining try code

---

# Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

## Overview

This exercise introduces exception handling in C++ by implementing a `Bureaucrat` class. The goal is to create a bureaucrat with a name and grade, where the grade must be validated and protected from invalid values using custom exceptions.

## Description

We're building the smallest cog in a bureaucratic machine - a **Bureaucrat**. This bureaucrat exists in a rigid hierarchy where grades matter, and any attempt to break the rules results in exceptions being thrown.

## Class Requirements

### Bureaucrat Class

The `Bureaucrat` class must have:

- **Constant name** (`const std::string`)
- **Grade** (integer from 1 to 150)
  - Grade 1 = Highest possible grade
  - Grade 150 = Lowest possible grade

### Member Functions

- `std::string getName() const` - Returns the bureaucrat's name
- `int getGrade() const` - Returns the bureaucrat's current grade
- `void incrementGrade()` - Decreases the grade number (increases rank)
- `void decrementGrade()` - Increases the grade number (decreases rank)

### Exception Classes

Two nested exception classes that inherit from `std::exception`:

- `Bureaucrat::GradeTooHighException` - Thrown when grade < 1
- `Bureaucrat::GradeTooLowException` - Thrown when grade > 150

These exceptions are thrown in the following situations:
- During construction if the initial grade is invalid
- When incrementing would make the grade < 1
- When decrementing would make the grade > 150

### Operator Overload

Overload the insertion operator (`<<`) to output:
```
<name>, bureaucrat grade <grade>.
```

Example: `"John, bureaucrat grade 42."`

## Key Concepts

### Grade Logic

**Important:** Grade numbers are inverse to rank!
- Lower number = Higher rank (1 is the best)
- Higher number = Lower rank (150 is the worst)

Therefore:
- `incrementGrade()` → grade 3 becomes grade 2 (promotion!)
- `decrementGrade()` → grade 3 becomes grade 4 (demotion!)

### Exception Handling

The exceptions must be catchable using standard try-catch blocks:

```cpp
try {
    Bureaucrat bob("Bob", 0);  // Too high!
} 
catch (std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

### Design Notes

- **Exception classes do NOT need Orthodox Canonical Form** (no need for copy constructor, assignment operator, etc.)
- **The Bureaucrat class MUST follow Orthodox Canonical Form**
- The name is constant and cannot be changed after construction
- All exceptions inherit from `std::exception` for polymorphic catching

## Testing

The implementation includes comprehensive tests to verify:

1. ✓ Valid bureaucrat creation with grades 1-150
2. ✓ Exception thrown for grade < 1 (GradeTooHighException)
3. ✓ Exception thrown for grade > 150 (GradeTooLowException)
4. ✓ Increment works correctly (promotes bureaucrat)
5. ✓ Decrement works correctly (demotes bureaucrat)
6. ✓ Exception thrown when incrementing grade 1
7. ✓ Exception thrown when decrementing grade 150
8. ✓ Insertion operator displays correct format
9. ✓ Exception messages are clear and informative

## Example Usage

```cpp
try {
    Bureaucrat alice("Alice", 2);
    std::cout << alice << std::endl;  // Alice, bureaucrat grade 2.
    
    alice.incrementGrade();  // Now grade 1
    std::cout << alice << std::endl;  // Alice, bureaucrat grade 1.
    
    alice.incrementGrade();  // Exception! Can't go higher than 1
}
catch (Bureaucrat::GradeTooHighException& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## Learning Objectives

- Understanding exception handling in C++
- Creating custom exception classes
- Using try-catch blocks effectively
- Throwing exceptions from constructors and member functions
- Implementing exception safety
- Following Orthodox Canonical Form for classes

## Compilation

```bash
make
./bureaucrat
```


---
