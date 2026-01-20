<!-- # C++ Module 05: Exception Handling

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

# Exercise 01: Form up, maggots!

## Overview

This exercise extends the bureaucratic system by introducing **Forms** that bureaucrats can sign. Forms have grade requirements, and only bureaucrats with sufficient grades can sign them.

## Key Concept: Forms and Signing Authority

Forms represent paperwork in our bureaucratic nightmare. Each form has:
- A name (constant)
- A signed status (boolean, starts as `false`)
- A grade required to sign it (constant)
- A grade required to execute it (constant)

**Core idea:** Bureaucrats can only sign forms if their grade is high enough (remember: lower number = higher authority).

## Class Requirements

### Form Class

The `Form` class must have:

- **Constant name** (`const std::string`)
- **Signed status** (boolean, initialized to `false`)
- **Grade required to sign** (constant, 1-150)
- **Grade required to execute** (constant, 1-150)

All attributes must be **private** (not protected).

### Member Functions

- `std::string getName() const` - Returns the form's name
- `bool isSigned() const` - Returns whether the form is signed
- `int getGradeToSign() const` - Returns grade required to sign
- `int getGradeToExecute() const` - Returns grade required to execute
- `void beSigned(const Bureaucrat& bureaucrat)` - Attempts to sign the form

### Exception Classes

Two nested exception classes:
- `Form::GradeTooHighException` - Thrown when grade < 1
- `Form::GradeTooLowException` - Thrown when grade > 150 or bureaucrat's grade is insufficient

### Operator Overload

Overload the insertion operator (`<<`) to display all form information.

## New Bureaucrat Function

Add to the `Bureaucrat` class:

- `void signForm(Form& form)` - Attempts to sign the form and prints result:
  - Success: `"<bureaucrat> signed <form>"`
  - Failure: `"<bureaucrat> couldn't sign <form> because <reason>"`

## Signing Logic

When `beSigned()` is called:
1. Check if bureaucrat's grade is **high enough** (number is low enough)
2. If yes → Change form status to signed
3. If no → Throw `Form::GradeTooLowException`

## Example Usage

```cpp
try {
    Bureaucrat alice("Alice", 50);
    Form taxForm("Tax Form 2024", 45, 30);
    
    std::cout << taxForm << std::endl;  // Shows unsigned form
    
    alice.signForm(taxForm);  // Alice (grade 50) tries to sign (requires 45)
    // Output: "Alice couldn't sign Tax Form 2024 because grade too low"
    
    alice.incrementGrade();  // Multiple promotions...
    // ... until grade is 45 or better
    
    alice.signForm(taxForm);  // Now succeeds!
    // Output: "Alice signed Tax Form 2024"
}
catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## Learning Objectives

- Object interaction (Bureaucrat ↔ Form)
- Authorization and permission systems
- Exception handling across multiple classes
- Designing class relationships

---

# Exercise 02: No, you need form 28B, not 28C...

## Overview

This exercise introduces **concrete form types** that actually perform actions when executed. The base `Form` class becomes abstract (`AForm`), and three specific form types are implemented, each with unique behaviors.

## Key Concept: Polymorphism and Form Execution

Forms now **do something** when executed. Different form types perform different actions, demonstrating polymorphism in action.

**Important:** The base class `Form` is renamed to `AForm` (Abstract Form) and contains a pure virtual `execute()` function.

## AForm (Abstract Base Class)

The abstract base class must have:

- All previous `Form` attributes and functions
- **New pure virtual function:** `void execute(const Bureaucrat& executor) const`

### Execution Requirements

Before executing, the form must check:
1. The form is **signed**
2. The executor's grade is **high enough** (≤ required execution grade)

If either check fails → throw an appropriate exception.

## Concrete Form Classes

### 1. ShrubberyCreationForm

**Grades:** Sign 145, Execute 137

**Action:** Creates a file `<target>_shrubbery` in the working directory containing ASCII trees.

```
Example target: "home"
Creates: home_shrubbery
Contains: ASCII art trees
```

### 2. RobotomyRequestForm

**Grades:** Sign 72, Execute 45

**Action:** 
- Makes drilling noises (print sound effects)
- **50% success rate:** Randomly succeeds or fails
- Success: `"<target> has been robotomized successfully"`
- Failure: `"Robotomy failed on <target>"`

### 3. PresidentialPardonForm

**Grades:** Sign 25, Execute 5

**Action:** Announces that `<target>` has been pardoned by Zaphod Beeblebrox.

Output: `"<target> has been pardoned by Zaphod Beeblebrox"`

## Class Design

All concrete forms:
- Take **one parameter** in constructor: the target (string)
- Inherit from `AForm`
- Implement the `execute()` function
- Have **fixed** sign/exec grades (passed to base class constructor)

## New Bureaucrat Function

Add to the `Bureaucrat` class:

- `void executeForm(const AForm& form) const` - Attempts to execute the form:
  - Success: `"<bureaucrat> executed <form>"`
  - Failure: Print explicit error message

## Implementation Pattern

**Elegant approach:** Perform checks in the base class `AForm::execute()`, then call a protected pure virtual function like `executeAction()` in derived classes.

```cpp
// In AForm (base class)
void execute(const Bureaucrat& executor) const {
    // Check if signed
    // Check executor's grade
    // If all good, call executeAction()
}

// In derived classes
void executeAction() const override {
    // Perform specific action (plant trees, robotomize, etc.)
}
```

## Example Usage

```cpp
try {
    Bureaucrat ceo("CEO", 1);  // Highest grade
    Bureaucrat intern("Intern", 150);  // Lowest grade
    
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");
    
    // CEO signs all forms (grade 1 can sign anything)
    ceo.signForm(shrub);
    ceo.signForm(robot);
    ceo.signForm(pardon);
    
    // CEO executes all forms
    ceo.executeForm(shrub);   // Creates garden_shrubbery file
    ceo.executeForm(robot);   // 50% chance of success
    ceo.executeForm(pardon);  // Pardons Arthur Dent
    
    // Intern tries to execute (will fail - grade too low)
    intern.executeForm(pardon);  // Exception!
}
catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## Learning Objectives

- Abstract classes and pure virtual functions
- Polymorphism in practice
- Base class vs derived class responsibilities
- File I/O operations (ShrubberyCreationForm)
- Randomness in C++ (RobotomyRequestForm)

---

# Exercise 03: At least this beats coffee-making

## Overview

This exercise introduces the **Intern** class, which can dynamically create forms based on string input. This demonstrates the **Factory Pattern** and dynamic object creation.

## Key Concept: Factory Pattern

The intern acts as a **form factory** - you give it a form name (string), and it creates the appropriate form object for you.

**Important:** Avoid ugly if-else chains! Use a clean, elegant solution (function pointer arrays, maps, or similar approaches).

## Intern Class

The `Intern` class has:
- **No name**
- **No grade**
- **No unique characteristics**
- **One important function:** `makeForm()`

### The makeForm() Function

```cpp
AForm* makeForm(std::string formName, std::string target);
```

**Parameters:**
- `formName` - Name of the form to create ("shrubbery creation", "robotomy request", "presidential pardon")
- `target` - Target for the form

**Returns:** Pointer to a newly created `AForm` object (or `NULL` if form name is invalid)

**Output:** `"Intern creates <form>"` on success, or explicit error message on failure.

## Form Name Mapping

The intern recognizes these form names:
- `"shrubbery creation"` → ShrubberyCreationForm
- `"robotomy request"` → RobotomyRequestForm
- `"presidential pardon"` → PresidentialPardonForm

Case sensitivity and exact matching are up to your implementation.

## Clean Implementation

**❌ BAD (unreadable if-else chain):**
```cpp
if (formName == "shrubbery creation")
    return new ShrubberyCreationForm(target);
else if (formName == "robotomy request")
    return new RobotomyRequestForm(target);
else if (formName == "presidential pardon")
    return new PresidentialPardonForm(target);
else
    return NULL;
```

**✓ GOOD (clean, scalable solution):**
Use function pointers, arrays, maps, or other elegant approaches that avoid repetitive if-else structures.

## Example Usage

```cpp
int main() {
    Intern someRandomIntern;
    AForm* form1;
    AForm* form2;
    AForm* form3;
    
    form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    // Output: "Intern creates robotomy request"
    
    form2 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    // Output: "Intern creates presidential pardon"
    
    form3 = someRandomIntern.makeForm("invalid form", "Target");
    // Output: Error message, form3 is NULL
    
    // Use the forms
    Bureaucrat boss("Boss", 1);
    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    
    // Clean up
    delete form2;
    delete form3;
    
    return 0;
}
```

## Memory Management

**Critical:** The `makeForm()` function returns a **dynamically allocated** object (using `new`). The caller is responsible for deleting it to avoid memory leaks!

```cpp
AForm* form = intern.makeForm("shrubbery creation", "office");
// ... use the form ...
delete form;  // Don't forget this!
```

## Learning Objectives

- Factory design pattern
- Dynamic object creation
- Function pointers or alternative elegant solutions
- Avoiding code duplication and if-else chains
- Proper memory management with dynamic allocation

---

## Module 05 Summary

Throughout this module, you've built a complete bureaucratic system demonstrating:

1. **Exception Handling** - Creating and throwing custom exceptions for error conditions
2. **Class Relationships** - Bureaucrats interact with Forms through signing and execution
3. **Polymorphism** - Abstract base class with concrete implementations for different form types
4. **Factory Pattern** - Dynamic object creation through the Intern class
5. **Authorization Systems** - Grade-based permissions for signing and executing forms

**Key Takeaway:** This module teaches you how to design robust, interconnected class systems with proper error handling and polymorphic behavior - essential skills for real-world C++ development. -->

# C++ Module 05: Exception Handling

## Table of Contents
1. [Quick Reference](#quick-reference)
2. [Exception Handling in C++](#exception-handling-in-c)
3. [Exercise 00: Bureaucrat](#exercise-00-mommy-when-i-grow-up-i-want-to-be-a-bureaucrat)
4. [Exercise 01: Form up, maggots!](#exercise-01-form-up-maggots)
5. [Exercise 02: No, you need form 28B, not 28C...](#exercise-02-no-you-need-form-28b-not-28c)
6. [Exercise 03: At least this beats coffee-making](#exercise-03-at-least-this-beats-coffee-making)
7. [Common Mistakes to Avoid](#common-mistakes-to-avoid)
8. [Compilation & Testing](#compilation--testing)
9. [Module Summary](#module-05-summary)

---

## Quick Reference

**TL;DR for each exercise:**
- **Ex00:** Custom exceptions, Bureaucrat class with grade validation (1-150)
- **Ex01:** Forms with signing requirements, bureaucrat-form interaction
- **Ex02:** Abstract forms (`AForm`) + 3 concrete types with execution (polymorphism)
- **Ex03:** Factory pattern with Intern class for dynamic form creation

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

### Orthodox Canonical Form Reminder

All classes (except exceptions) need:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

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

# Exercise 01: Form up, maggots!

## Overview

This exercise extends the bureaucratic system by introducing **Forms** that bureaucrats can sign. Forms have grade requirements, and only bureaucrats with sufficient grades can sign them.

## Key Concept: Forms and Signing Authority

Forms represent paperwork in our bureaucratic nightmare. Each form has:
- A name (constant)
- A signed status (boolean, starts as `false`)
- A grade required to sign it (constant)
- A grade required to execute it (constant)

**Core idea:** Bureaucrats can only sign forms if their grade is high enough (remember: lower number = higher authority).

## Class Requirements

### Form Class

The `Form` class must have:

- **Constant name** (`const std::string`)
- **Signed status** (boolean, initialized to `false`)
- **Grade required to sign** (constant, 1-150)
- **Grade required to execute** (constant, 1-150)

All attributes must be **private** (not protected).

### Member Functions

- `std::string getName() const` - Returns the form's name
- `bool isSigned() const` - Returns whether the form is signed
- `int getGradeToSign() const` - Returns grade required to sign
- `int getGradeToExecute() const` - Returns grade required to execute
- `void beSigned(const Bureaucrat& bureaucrat)` - Attempts to sign the form

### Exception Classes

Two nested exception classes:
- `Form::GradeTooHighException` - Thrown when grade < 1
- `Form::GradeTooLowException` - Thrown when grade > 150 or bureaucrat's grade is insufficient

### Operator Overload

Overload the insertion operator (`<<`) to display all form information.

## New Bureaucrat Function

Add to the `Bureaucrat` class:

- `void signForm(Form& form)` - Attempts to sign the form and prints result:
  - Success: `"<bureaucrat> signed <form>"`
  - Failure: `"<bureaucrat> couldn't sign <form> because <reason>"`

## Signing Logic

When `beSigned()` is called:
1. Check if bureaucrat's grade is **high enough** (number is low enough)
2. If yes → Change form status to signed
3. If no → Throw `Form::GradeTooLowException`

## Example Usage

```cpp
try {
    Bureaucrat alice("Alice", 50);
    Form taxForm("Tax Form 2024", 45, 30);
    
    std::cout << taxForm << std::endl;  // Shows unsigned form
    
    alice.signForm(taxForm);  // Alice (grade 50) tries to sign (requires 45)
    // Output: "Alice couldn't sign Tax Form 2024 because grade too low"
    
    // Multiple promotions until grade is 45 or better
    while (alice.getGrade() > 45)
        alice.incrementGrade();
    
    alice.signForm(taxForm);  // Now succeeds!
    // Output: "Alice signed Tax Form 2024"
}
catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## Learning Objectives

- Object interaction (Bureaucrat ↔ Form)
- Authorization and permission systems
- Exception handling across multiple classes
- Designing class relationships

---

# Exercise 02: No, you need form 28B, not 28C...

## Overview

This exercise introduces **concrete form types** that actually perform actions when executed. The base `Form` class becomes abstract (`AForm`), and three specific form types are implemented, each with unique behaviors.

## Key Concept: Polymorphism and Form Execution

Forms now **do something** when executed. Different form types perform different actions, demonstrating polymorphism in action.

**Important:** The base class `Form` is renamed to `AForm` (Abstract Form) and contains a pure virtual `execute()` function.

## AForm (Abstract Base Class)

The abstract base class must have:

- All previous `Form` attributes and functions
- **New pure virtual function:** `void execute(const Bureaucrat& executor) const`

### Execution Requirements

Before executing, the form must check:
1. The form is **signed**
2. The executor's grade is **high enough** (≤ required execution grade)

If either check fails → throw an appropriate exception.

## Concrete Form Classes

### 1. ShrubberyCreationForm

**Grades:** Sign 145, Execute 137

**Action:** Creates a file `<target>_shrubbery` in the working directory containing ASCII trees.

```
Example target: "home"
Creates: home_shrubbery
Contains: ASCII art trees like:

       _-_
    /~~   ~~\
 /~~         ~~\
{               }
 \  _-     -_  /
   ~  \\ //  ~
```

### 2. RobotomyRequestForm

**Grades:** Sign 72, Execute 45

**Action:** 
- Makes drilling noises (print sound effects like "* BZZZZZZT WHIRRRRR DRRRRR *")
- **50% success rate:** Randomly succeeds or fails
- Success: `"<target> has been robotomized successfully"`
- Failure: `"Robotomy failed on <target>"`

### 3. PresidentialPardonForm

**Grades:** Sign 25, Execute 5

**Action:** Announces that `<target>` has been pardoned by Zaphod Beeblebrox.

Output: `"<target> has been pardoned by Zaphod Beeblebrox"`

## Class Design

All concrete forms:
- Take **one parameter** in constructor: the target (string)
- Inherit from `AForm`
- Implement the `execute()` function
- Have **fixed** sign/exec grades (passed to base class constructor)

## New Bureaucrat Function

Add to the `Bureaucrat` class:

- `void executeForm(const AForm& form) const` - Attempts to execute the form:
  - Success: `"<bureaucrat> executed <form>"`
  - Failure: Print explicit error message

## Implementation Pattern

**Elegant approach:** Perform checks in the base class `AForm::execute()`, then call a protected pure virtual function like `executeAction()` in derived classes.

```cpp
// In AForm (base class)
void execute(const Bureaucrat& executor) const {
    // Check if signed
    // Check executor's grade
    // If all good, call executeAction()
}

// In derived classes
void executeAction() const override {
    // Perform specific action (plant trees, robotomize, etc.)
}
```

## Example Usage

```cpp
try {
    Bureaucrat ceo("CEO", 1);  // Highest grade
    Bureaucrat intern("Intern", 150);  // Lowest grade
    
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");
    
    // CEO signs all forms (grade 1 can sign anything)
    ceo.signForm(shrub);
    ceo.signForm(robot);
    ceo.signForm(pardon);
    
    // CEO executes all forms
    ceo.executeForm(shrub);   // Creates garden_shrubbery file
    ceo.executeForm(robot);   // 50% chance of success
    ceo.executeForm(pardon);  // Pardons Arthur Dent
    
    // Intern tries to execute (will fail - grade too low)
    intern.executeForm(pardon);  // Exception!
}
catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## Learning Objectives

- Abstract classes and pure virtual functions
- Polymorphism in practice
- Base class vs derived class responsibilities
- File I/O operations (ShrubberyCreationForm)
- Randomness in C++ (RobotomyRequestForm)

---

# Exercise 03: At least this beats coffee-making

## Overview

This exercise introduces the **Intern** class, which can dynamically create forms based on string input. This demonstrates the **Factory Pattern** and dynamic object creation.

## Key Concept: Factory Pattern

The intern acts as a **form factory** - you give it a form name (string), and it creates the appropriate form object for you.

**Important:** Avoid ugly if-else chains! Use a clean, elegant solution (function pointer arrays, maps, or similar approaches).

## Intern Class

The `Intern` class has:
- **No name**
- **No grade**
- **No unique characteristics**
- **One important function:** `makeForm()`

### The makeForm() Function

```cpp
AForm* makeForm(std::string formName, std::string target);
```

**Parameters:**
- `formName` - Name of the form to create ("shrubbery creation", "robotomy request", "presidential pardon")
- `target` - Target for the form

**Returns:** Pointer to a newly created `AForm` object (or `NULL`/`nullptr` if form name is invalid)

**Output:** `"Intern creates <form>"` on success, or explicit error message on failure.

## Form Name Mapping

The intern recognizes these form names:
- `"shrubbery creation"` → ShrubberyCreationForm
- `"robotomy request"` → RobotomyRequestForm
- `"presidential pardon"` → PresidentialPardonForm

Case sensitivity and exact matching are up to your implementation.

## Clean Implementation

**❌ BAD (unreadable if-else chain):**
```cpp
if (formName == "shrubbery creation")
    return new ShrubberyCreationForm(target);
else if (formName == "robotomy request")
    return new RobotomyRequestForm(target);
else if (formName == "presidential pardon")
    return new PresidentialPardonForm(target);
else
    return NULL;
```

**✓ GOOD (clean, scalable solution):**
Use function pointers, arrays, maps, or other elegant approaches that avoid repetitive if-else structures.

**Hint:** Think about storing form names and their corresponding constructor calls in a data structure. What C++ feature lets you store function-like behavior? Consider arrays of structs containing strings and function pointers.

## Example Usage

```cpp
int main() {
    Intern someRandomIntern;
    AForm* form1;
    AForm* form2;
    AForm* form3;
    
    form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    // Output: "Intern creates robotomy request"
    
    form2 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    // Output: "Intern creates presidential pardon"
    
    form3 = someRandomIntern.makeForm("invalid form", "Target");
    // Output: Error message, form3 is NULL
    
    // Use the forms
    Bureaucrat boss("Boss", 1);
    if (form1) {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    
    // Clean up
    delete form2;
    if (form3)
        delete form3;
    
    return 0;
}
```

## Memory Management

**Critical:** The `makeForm()` function returns a **dynamically allocated** object (using `new`). The caller is responsible for deleting it to avoid memory leaks!

```cpp
AForm* form = intern.makeForm("shrubbery creation", "office");
// ... use the form ...
delete form;  // Don't forget this!
```

## Learning Objectives

- Factory design pattern
- Dynamic object creation
- Function pointers or alternative elegant solutions
- Avoiding code duplication and if-else chains
- Proper memory management with dynamic allocation

---

## Common Mistakes to Avoid

Throughout this module, watch out for these frequent pitfalls:

### Memory Management
- ❌ Forgetting to delete dynamically allocated forms (Ex03)
- ❌ Not checking for NULL before using a form pointer
- ✓ Always use `delete` for objects created with `new`
- ✓ Test with `valgrind` to catch memory leaks

### Class Design
- ❌ Using `protected` instead of `private` attributes in Form/AForm
- ❌ Forgetting Orthodox Canonical Form for classes (not exceptions)
- ✓ All class attributes should be private
- ✓ Exception classes don't need Orthodox Canonical Form

### Grade Logic
- ❌ Confusing grade numbers (remember: **1 = best, 150 = worst!**)
- ❌ Incrementing grade by adding 1 (should subtract!)
- ✓ `incrementGrade()` decreases the number (promotes)
- ✓ `decrementGrade()` increases the number (demotes)

### Execution Flow
- ❌ Not checking if form is signed before executing
- ❌ Not validating executor's grade during execution
- ✓ Always check: (1) form is signed, (2) grade is sufficient
- ✓ Throw appropriate exceptions when checks fail

### Code Quality
- ❌ Using long if-else chains in Exercise 03
- ❌ Hardcoding values instead of using constants
- ✓ Use elegant solutions (function pointers, arrays, etc.)
- ✓ Keep code DRY (Don't Repeat Yourself)

---

## Compilation & Testing

### Makefile Requirements

Your Makefile must include:
- **Compiler:** `c++`
- **Flags:** `-Wall -Wextra -Werror -std=c++98`
- **No relink:** Running `make` twice should not recompile
- **Standard rules:** `all`, `clean`, `fclean`, `re`

Example:
```makefile
NAME = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

### Testing Strategy

**1. Boundary Value Testing**
```cpp
// Test edge cases for grades
Bureaucrat min("Min", 150);    // Lowest valid
Bureaucrat max("Max", 1);      // Highest valid
Bureaucrat invalid1("Bad", 0);      // Should throw
Bureaucrat invalid2("Bad", 151);    // Should throw
```

**2. Exception Testing**
```cpp
// Verify exceptions are thrown and catchable
try {
    Bureaucrat bob("Bob", 1);
    bob.incrementGrade();  // Should throw GradeTooHighException
}
catch (Bureaucrat::GradeTooHighException& e) {
    std::cout << "Caught: " << e.what() << std::endl;
}
```

**3. Form Execution Testing**
```cpp
// Test execution without signing
AForm* form = new ShrubberyCreationForm("test");
Bureaucrat exec("Exec", 1);
exec.executeForm(*form);  // Should fail - not signed
delete form;
```

**4. Memory Leak Testing**
```bash
# Compile with debug symbols
c++ -Wall -Wextra -Werror -std=c++98 -g *.cpp -o bureaucrat

# Run with valgrind
valgrind --leak-check=full ./bureaucrat

# Should show: "All heap blocks were freed -- no leaks are possible"
```

### Testing Checklist

#### Exercise 00
- [ ] Valid bureaucrat creation (grades 1-150)
- [ ] Exception for grade 0 (too high)
- [ ] Exception for grade 151 (too low)
- [ ] Increment/decrement work correctly
- [ ] Exception when incrementing grade 1
- [ ] Exception when decrementing grade 150
- [ ] Insertion operator outputs correct format
- [ ] Copy constructor and assignment operator work

#### Exercise 01
- [ ] Form creation with valid grades
- [ ] Exception for invalid form grades
- [ ] Signing succeeds with sufficient grade
- [ ] Signing fails with insufficient grade
- [ ] signForm() prints appropriate messages
- [ ] Insertion operator shows all form info

#### Exercise 02
- [ ] All three concrete forms compile
- [ ] ShrubberyCreationForm creates file with trees
- [ ] RobotomyRequestForm has ~50% success rate
- [ ] PresidentialPardonForm outputs correct message
- [ ] Execution fails on unsigned forms
- [ ] Execution fails with insufficient grade
- [ ] executeForm() prints appropriate messages

#### Exercise 03
- [ ] Intern creates all three form types
- [ ] Invalid form name handled gracefully
- [ ] No memory leaks when creating forms
- [ ] Implementation avoids if-else chains
- [ ] Forms created by intern work correctly

---

## Module 05 Summary

Throughout this module, you've built a complete bureaucratic system demonstrating:

### Core Concepts Learned

1. **Exception Handling**
   - Creating custom exception classes
   - Throwing and catching exceptions
   - Exception safety in constructors
   - Proper error message formatting

2. **Class Relationships**
   - Bureaucrats interact with Forms
   - Authorization through grade comparison
   - Bidirectional communication between objects

3. **Polymorphism**
   - Abstract base class (`AForm`)
   - Concrete implementations with unique behaviors
   - Pure virtual functions
   - Virtual destructors

4. **Factory Pattern**
   - Dynamic object creation
   - String-to-object mapping
   - Encapsulation of creation logic
   - Clean, maintainable code structure

5. **Authorization Systems**
   - Grade-based permissions
   - Two-level authorization (sign + execute)
   - Validation at multiple points

### Design Patterns Applied

- **Strategy Pattern** - Different form execution strategies
- **Factory Pattern** - Intern creates forms dynamically
- **Template Method** - Base class defines execution flow

### C++98 Skills Developed

- Exception hierarchies with `std::exception`
- Orthodox Canonical Form
- Const correctness
- File I/O operations
- Function pointers
- Operator overloading

### Key Takeaway

This module teaches you how to design **robust, interconnected class systems** with proper error handling and polymorphic behavior - essential skills for real-world C++ development. You've learned not just the syntax, but the architectural patterns that make large codebases maintainable and extensible.

---

**Good luck with your implementation! Remember: bureaucracy is tedious, but the lessons learned are invaluable.** 📋✨