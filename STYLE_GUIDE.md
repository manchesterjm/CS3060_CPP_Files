# C++ Style Guide

**CS3060 - Coding Standards**

**Version**: 1.0
**Last Updated**: November 2, 2025
**Project**: CS3060 C++ Programming Course

This document defines the coding standards for all C++ code in this project. Following these guidelines ensures consistency, maintainability, and code quality.

---

## Table of Contents

1. [General Principles](#general-principles)
2. [File Organization](#file-organization)
3. [Naming Conventions](#naming-conventions)
4. [Code Formatting](#code-formatting)
5. [Headers and Includes](#headers-and-includes)
6. [Classes and Objects](#classes-and-objects)
7. [Functions and Methods](#functions-and-methods)
8. [Documentation](#documentation)
9. [Memory Management](#memory-management)
10. [Error Handling](#error-handling)
11. [Const Correctness](#const-correctness)
12. [STL Usage](#stl-usage)
13. [Operator Overloading](#operator-overloading)
14. [Inheritance and Polymorphism](#inheritance-and-polymorphism)
15. [Code Review Checklist](#code-review-checklist)

---

## General Principles

### Core Values
1. **Readability First**: Code is read more often than written
2. **Explicit is Better Than Implicit**: Clear over clever
3. **Consistency**: Follow existing patterns in the codebase
4. **DRY (Don't Repeat Yourself)**: Extract common functionality
5. **RAII (Resource Acquisition Is Initialization)**: Tie resource lifetime to object lifetime
6. **Const Correctness**: Use const wherever possible

### Code Quality Standards
- **Compilation**: Code must compile without errors or warnings
- **Linting**: Use clang++ with `-Wall -Wextra` for static analysis
- **Testing**: Test all functionality before submission
- **No Memory Leaks**: All dynamically allocated memory must be freed

---

## File Organization

### Header Files (.h)

```cpp
// File: TestScores.h
#ifndef TEST_SCORES_H    // Include guard (must be unique)
#define TEST_SCORES_H

// System includes first
#include <string>
#include <vector>

// Class declaration with forward declarations if needed
class User;  // Forward declaration

/**
 * Brief description of the class.
 *
 * Detailed description of what this class does and how to use it.
 */
class TestScores {
private:
    // Private members first
    int numScores;
    int* scores;

public:
    // Constructors
    TestScores();
    TestScores(int scoreArray[], int size);

    // Destructor
    ~TestScores();

    // Copy constructor and assignment operator (if needed)
    TestScores(const TestScores& other);
    TestScores& operator=(const TestScores& other);

    // Public methods
    double getAverage() const;
    void addScore(int score);
};

#endif // TEST_SCORES_H
```

### Implementation Files (.cpp)

```cpp
// File: TestScores.cpp
#include "TestScores.h"      // Corresponding header first
#include <iostream>          // System headers
#include <stdexcept>         // Standard library headers
#include "NegativeScore.h"   // Other project headers

using namespace std;

// Constructor implementation
TestScores::TestScores(int scoreArray[], int size) {
    numScores = size;
    scores = new int[size];

    for (int index = 0; index < size; index++) {
        if (scoreArray[index] < 0) {
            throw NegativeScore(scoreArray[index]);
        }
        scores[index] = scoreArray[index];
    }
}

// Method implementation
double TestScores::getAverage() const {
    int total = 0;
    for (int index = 0; index < numScores; index++) {
        total += scores[index];
    }
    return static_cast<double>(total) / numScores;
}
```

### Main Files

```cpp
// File: main.cpp or assignment.cpp
#include <iostream>
#include <string>
#include "TestScores.h"
#include "NegativeScore.h"

using namespace std;

int main() {
    try {
        int myScores[5] = {88, 90, 93, 87, 99};
        TestScores myTestScores(myScores, 5);

        cout << "The average score is "
             << myTestScores.getAverage() << endl;
    }
    catch (const NegativeScore& e) {
        cout << "An invalid score was found: "
             << e.getScore() << endl;
    }

    return 0;
}
```

---

## Naming Conventions

### File Naming

```cpp
// Source files (.cpp): PascalCase with descriptive names
BasicIO.cpp              // GOOD: Clear purpose
KineticEnergy.cpp        // GOOD: Describes functionality
RationalNumber.cpp       // GOOD: Class name matches
CarClass.cpp             // GOOD: Descriptive
MonkeyBusiness.cpp       // GOOD: Assignment name
TestScores.cpp           // GOOD: Matches class

// Avoid date-based or cryptic names
29_Jan_02.cpp            // BAD: Not descriptive
homework_1.cpp           // BAD: Not specific enough
prog1.cpp                // BAD: Too generic
test.cpp                 // BAD: Unclear purpose

// Header files (.h): Match the class or module name
TestScores.h             // GOOD: Matches TestScores class
NegativeScore.h          // GOOD: Matches NegativeScore class
utilities.h              // GOOD: Describes module contents
```

### General Rules

```cpp
// Classes: PascalCase (capitalize first letter of each word)
class TestScores { };
class GroupCalendar { };
class NegativeScore { };

// Functions and methods: camelCase (lowercase first, then capitalize each word)
void calculateAverage();
int getScore() const;
void setUserName(string name);

// Variables: camelCase
int userCount = 10;
string firstName;
double averageScore;

// Constants: UPPERCASE_WITH_UNDERSCORES
const double PI = 3.14159;
const int MAX_STUDENTS = 100;
const int DEFAULT_SIZE = 50;

// Private member variables: can use trailing underscore or prefix
class MyClass {
private:
    int count_;        // Trailing underscore (recommended)
    string name_;      // Shows it's a member variable

    // OR
    int m_count;       // Prefix with m_ (alternative style)
    string m_name;
};

// Function parameters: camelCase, descriptive names
void processData(int studentCount, double averageGrade);

// Loop variables: single letter acceptable for simple loops
for (int i = 0; i < size; i++) {
    // Use descriptive names for nested or complex loops
    for (int studentIndex = 0; studentIndex < count; studentIndex++) {
        // ...
    }
}
```

### Boolean Variables

```cpp
// Use is_, has_, can_, should_ prefixes for booleans
bool isActive = true;
bool hasPermission = false;
bool canEdit = true;
bool shouldRetry = false;

// BAD: Ambiguous names
bool active = true;      // Is this a boolean or status code?
bool permission = false; // What does false mean?
```

---

## Code Formatting

### Indentation and Bracing

```cpp
// Use 4 spaces for indentation (configure editor, never use tabs)
// Opening brace on same line (K&R style) - common in educational C++

// GOOD
class MyClass {
    void myMethod() {
        if (condition) {
            doSomething();
        }
    }
};

// ALSO ACCEPTABLE: Allman style (braces on new line)
class MyClass
{
    void myMethod()
    {
        if (condition)
        {
            doSomething();
        }
    }
};

// BE CONSISTENT: Choose one style and stick with it throughout the file
```

### Line Length

```cpp
// Keep lines under 100-120 characters for readability

// BAD: Line too long
cout << "This is a very long message that exceeds the maximum line length and should be broken into multiple lines" << endl;

// GOOD: Break into multiple lines
cout << "This is a very long message that has been broken "
     << "into multiple lines for better readability" << endl;
```

### Whitespace

```cpp
// Spaces around binary operators
int sum = a + b;
bool result = (x == 5);

// Space after commas
myFunction(a, b, c);

// No space between function name and parentheses
calculateSum(x, y);    // GOOD
calculateSum (x, y);   // BAD

// Space after control flow keywords
if (condition) { }     // GOOD
if(condition) { }      // BAD

for (int i = 0; i < n; i++) { }   // GOOD
for(int i=0;i<n;i++) { }          // BAD
```

### Blank Lines

```cpp
// One blank line between function definitions
void firstFunction() {
    // Implementation
}

void secondFunction() {
    // Implementation
}

// Use blank lines to separate logical sections
void complexFunction() {
    // Setup phase
    int data = fetchData();

    // Processing phase
    int result = processData(data);

    // Output phase
    cout << result << endl;
}
```

---

## Headers and Includes

### Include Guards

```cpp
// Always use include guards in header files
// Format: FILENAME_H or PROJECT_FILENAME_H

// testscores.h
#ifndef TEST_SCORES_H
#define TEST_SCORES_H

// ... class declaration ...

#endif // TEST_SCORES_H

// Alternative: #pragma once (non-standard but widely supported)
#pragma once

// ... class declaration ...
```

### Include Order

```cpp
// 1. Corresponding header (for .cpp files)
#include "TestScores.h"

// 2. C system headers
#include <cmath>
#include <cstdlib>

// 3. C++ standard library headers (alphabetical)
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 4. Project headers (alphabetical)
#include "NegativeScore.h"
#include "UserProfile.h"

using namespace std;  // Only in .cpp files, NEVER in .h files
```

### Using Namespace

```cpp
// GOOD: Using namespace in .cpp files (educational context)
#include <iostream>
using namespace std;

int main() {
    cout << "Hello" << endl;
    return 0;
}

// NEVER in header files - pollutes global namespace
// BAD in .h file:
#ifndef MYCLASS_H
#define MYCLASS_H
using namespace std;  // NEVER do this!
#endif

// GOOD in .h file:
#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>

class MyClass {
private:
    std::string name;  // Use std:: prefix in headers
};
#endif
```

---

## Classes and Objects

### Class Structure

```cpp
// Order: public, protected, private (most accessible first)
// Within each section: constructors, destructor, operators, methods, data

class Car {
public:
    // Constructors
    Car();
    Car(int year, string make);

    // Destructor
    ~Car();

    // Copy constructor and assignment operator
    Car(const Car& other);
    Car& operator=(const Car& other);

    // Getters (const methods)
    int getYearModel() const;
    string getMake() const;
    int getSpeed() const;

    // Setters
    void setModel(int year);
    void setMake(string make);

    // Other public methods
    void accelerate();
    void brake();

private:
    // Data members
    int yearModel_;
    string make_;
    int speed_;

    // Private helper methods
    void validateSpeed();
};
```

### Constructor Initialization Lists

```cpp
// GOOD: Use initialization lists (more efficient)
Car::Car(int year, string mk) : yearModel_(year), make_(mk), speed_(0) {
    // Body for additional logic if needed
}

// ACCEPTABLE: Assignment in constructor body (less efficient)
Car::Car(int year, string mk) {
    yearModel_ = year;
    make_ = mk;
    speed_ = 0;
}

// REQUIRED: For const members and references, must use initialization list
class Student {
private:
    const int id_;           // Must be initialized
    string& nameRef_;        // Must be initialized

public:
    Student(int id, string& name) : id_(id), nameRef_(name) {
        // const and references MUST use initialization list
    }
};
```

### The Big Three (Rule of Three)

```cpp
// If you define any of: destructor, copy constructor, or copy assignment
// You should define all three

class DynamicArray {
private:
    int* data_;
    int size_;

public:
    // Constructor
    DynamicArray(int size) : size_(size) {
        data_ = new int[size_];
    }

    // 1. Destructor
    ~DynamicArray() {
        delete[] data_;
    }

    // 2. Copy constructor
    DynamicArray(const DynamicArray& other) : size_(other.size_) {
        data_ = new int[size_];
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    // 3. Copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {  // Check for self-assignment
            // Clean up existing resources
            delete[] data_;

            // Copy from other
            size_ = other.size_;
            data_ = new int[size_];
            for (int i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }
};
```

---

## Functions and Methods

### Function Design

```cpp
// Keep functions focused and concise (generally <50 lines)

// BAD: Function does too many things
void processOrder(Order order) {
    // 100+ lines of validation, processing, emailing, logging...
}

// GOOD: Break into logical pieces
void processOrder(Order order) {
    if (!validateOrder(order)) {
        return;
    }

    updateInventory(order);
    chargeCustomer(order);
    sendConfirmationEmail(order);
    logOrderCompletion(order);
}

bool validateOrder(const Order& order) {
    return order.items.size() > 0 && order.customer != nullptr;
}
```

### Function Parameters

```cpp
// Pass large objects by const reference
void processData(const vector<int>& data);  // GOOD
void processData(vector<int> data);         // BAD: Copies entire vector

// Pass output parameters by reference or pointer
void calculateStats(const vector<int>& data, double& average, double& stdDev);

// Use default arguments for optional parameters
void printMessage(string msg, bool uppercase = false, int repeatCount = 1);

// Limit function parameters (≤5 ideal, ≤7 maximum)
// Too many? Group into a struct or class
struct UserProfile {
    string firstName;
    string lastName;
    string email;
    string phone;
};

void createUser(string username, string password, const UserProfile& profile);
```

### Return Values

```cpp
// Prefer single return point when practical

// GOOD: Single return (clear logic)
double calculateDiscount(double price, bool isPremium) {
    // Guard clauses for validation (early returns OK)
    if (price <= 0) {
        return 0;
    }

    // Main logic with single return
    double discount = 0;
    if (isPremium) {
        discount = price * 0.20;
    } else {
        discount = price * 0.10;
    }

    return discount;
}

// ACCEPTABLE: Early returns for error conditions
int divide(int a, int b) {
    if (b == 0) {
        cerr << "Error: Division by zero" << endl;
        return 0;  // Or throw exception
    }

    return a / b;
}
```

---

## Documentation

### File Headers

```cpp
// Include descriptive comment at top of each file
/**
 * File: TestScores.cpp
 * Author: Your Name
 * Date: November 2, 2025
 *
 * Description: Implementation of TestScores class for managing
 * and calculating statistics on student test scores.
 */

#include "TestScores.h"
```

### Function/Method Comments

```cpp
/**
 * Calculate the average of all test scores.
 *
 * @return The average score as a double. Returns 0.0 if no scores.
 * @throws std::runtime_error if numScores is negative
 */
double TestScores::getAverage() const {
    if (numScores <= 0) {
        return 0.0;
    }

    int total = 0;
    for (int i = 0; i < numScores; i++) {
        total += scores_[i];
    }

    return static_cast<double>(total) / numScores;
}
```

### Class Comments

```cpp
/**
 * TestScores class manages a collection of test scores.
 *
 * This class stores test scores in a dynamically allocated array
 * and provides methods for calculating statistics such as averages.
 * It validates that all scores are non-negative.
 *
 * Example usage:
 *   int scores[] = {85, 90, 78, 92};
 *   TestScores ts(scores, 4);
 *   cout << "Average: " << ts.getAverage() << endl;
 */
class TestScores {
    // ... class definition ...
};
```

### Inline Comments

```cpp
// Use comments to explain WHY, not WHAT

// BAD: Comment states the obvious
counter++;  // Increment counter

// GOOD: Comment explains reasoning
counter++;  // Account for zero-indexing in display

// Explain complex algorithms
// Boyer-Moore voting algorithm for finding majority element
int candidate = 0;
int count = 0;
for (int num : nums) {
    if (count == 0) {
        candidate = num;
    }
    count += (num == candidate) ? 1 : -1;
}
```

---

## Memory Management

### Dynamic Memory

```cpp
// Always pair new with delete, new[] with delete[]

// Single object
int* ptr = new int(42);
delete ptr;  // MUST delete

// Array
int* arr = new int[10];
delete[] arr;  // MUST use delete[] for arrays

// BAD: Memory leak
void leakyFunction() {
    int* data = new int[100];
    // ... use data ...
    // Forgot to delete[]!
}  // Memory leaked!

// GOOD: Clean up resources
void properFunction() {
    int* data = new int[100];
    // ... use data ...
    delete[] data;
}
```

### RAII (Resource Acquisition Is Initialization)

```cpp
// Let objects manage resources automatically

// Instead of manual memory management
void manualApproach() {
    int* data = new int[100];
    // ... use data ...
    delete[] data;  // Must remember to clean up
}

// BETTER: Use STL containers (automatic cleanup)
void raii Approach() {
    vector<int> data(100);
    // ... use data ...
}  // Automatically cleaned up when vector goes out of scope

// For custom resources, use RAII pattern
class FileHandler {
private:
    FILE* file_;

public:
    FileHandler(const char* filename) {
        file_ = fopen(filename, "r");
    }

    ~FileHandler() {
        if (file_) {
            fclose(file_);  // Automatic cleanup
        }
    }
};
```

---

## Error Handling

### Exceptions

```cpp
// Use exceptions for exceptional conditions

// Custom exception class
class NegativeScore {
private:
    int score_;

public:
    NegativeScore(int s) : score_(s) { }

    int getScore() const {
        return score_;
    }
};

// Throwing exceptions
void validateScore(int score) {
    if (score < 0) {
        throw NegativeScore(score);
    }
}

// Catching exceptions - catch by const reference
try {
    int scores[] = {85, -10, 90};
    TestScores ts(scores, 3);
}
catch (const NegativeScore& e) {
    cerr << "Invalid score: " << e.getScore() << endl;
}
catch (const std::exception& e) {  // Catch standard exceptions
    cerr << "Error: " << e.what() << endl;
}
catch (...) {  // Catch-all (use sparingly)
    cerr << "Unknown error occurred" << endl;
}
```

### Input Validation

```cpp
// Always validate user input

// GOOD: Validate and handle errors
void getUserAge() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (cin.fail()) {
        cin.clear();  // Clear error flags
        cin.ignore(10000, '\n');  // Discard invalid input
        cout << "Invalid input. Please enter a number." << endl;
        return;
    }

    if (age < 0 || age > 150) {
        cout << "Age must be between 0 and 150." << endl;
        return;
    }

    // Process valid age
}
```

---

## Const Correctness

### Const Member Functions

```cpp
class Student {
private:
    string name_;
    int grade_;

public:
    // Getters should be const - they don't modify the object
    string getName() const {
        return name_;
    }

    int getGrade() const {
        return grade_;
    }

    // Setters are not const - they modify the object
    void setGrade(int grade) {
        grade_ = grade;
    }

    // Mark any method that doesn't modify data as const
    bool isPassing() const {
        return grade_ >= 60;
    }
};
```

### Const Parameters

```cpp
// Use const for parameters that won't be modified

// Pass by const reference for large objects
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
}

// Const pointers
void processData(const int* data, int size) {
    // Can't modify data through pointer
    for (int i = 0; i < size; i++) {
        cout << data[i] << endl;
    }
}
```

---

## STL Usage

### Prefer STL Containers

```cpp
// Use vector instead of arrays when possible
vector<int> scores;  // GOOD: Dynamic, safe
int scores[100];     // OK for fixed size, but less flexible

// Use string instead of char arrays
string name;        // GOOD: Safe, convenient
char name[50];      // Avoid unless specifically required

// Other useful containers
#include <array>    // Fixed-size array with STL benefits
#include <map>      // Key-value pairs
#include <set>      // Unique elements
#include <queue>    // FIFO operations
```

### Common STL Patterns

```cpp
#include <vector>
#include <algorithm>
#include <string>

// Initializing containers
vector<int> nums = {1, 2, 3, 4, 5};
vector<string> names(10);  // 10 empty strings

// Iterating
for (int num : nums) {  // Range-based for loop (C++11)
    cout << num << " ";
}

for (size_t i = 0; i < nums.size(); i++) {  // Index-based
    nums[i] *= 2;
}

// Common operations
nums.push_back(6);           // Add element
nums.pop_back();             // Remove last
int size = nums.size();      // Get size
bool empty = nums.empty();   // Check if empty
nums.clear();                // Remove all elements

// Algorithms
sort(nums.begin(), nums.end());  // Sort ascending
reverse(nums.begin(), nums.end());  // Reverse order
int minVal = *min_element(nums.begin(), nums.end());
```

---

## Operator Overloading

### Member vs Friend Functions

```cpp
class Rational {
private:
    int numerator_;
    int denominator_;

public:
    Rational(int n = 0, int d = 1) : numerator_(n), denominator_(d) { }

    // MEMBER FUNCTION: Use for (Rational op Rational)
    Rational operator+(const Rational& rhs) const {
        return Rational(
            numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_,
            denominator_ * rhs.denominator_
        );
    }

    // FRIEND FUNCTION: Needed for (int op Rational)
    friend Rational operator+(int lhs, const Rational& rhs);

    // Assignment operators should be member functions
    Rational& operator=(const Rational& rhs) {
        if (this != &rhs) {
            numerator_ = rhs.numerator_;
            denominator_ = rhs.denominator_;
        }
        return *this;
    }

    void print() const {
        cout << numerator_ << "/" << denominator_ << endl;
    }
};

// Friend function implementation (outside class)
Rational operator+(int lhs, const Rational& rhs) {
    return Rational(lhs * rhs.denominator_ + rhs.numerator_, rhs.denominator_);
}

// Usage
Rational a(1, 2), b(1, 3);
Rational c = a + b;     // Calls member function
Rational d = 2 + b;     // Calls friend function
```

### Stream Operators

```cpp
class Point {
private:
    int x_, y_;

public:
    Point(int x = 0, int y = 0) : x_(x), y_(y) { }

    // << operator for output (must be friend or non-member)
    friend ostream& operator<<(ostream& os, const Point& p);

    // >> operator for input
    friend istream& operator>>(istream& is, Point& p);
};

// Output operator
ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x_ << ", " << p.y_ << ")";
    return os;
}

// Input operator
istream& operator>>(istream& is, Point& p) {
    is >> p.x_ >> p.y_;
    return is;
}

// Usage
Point p(3, 4);
cout << p << endl;  // Prints: (3, 4)
```

---

## Inheritance and Polymorphism

### Basic Inheritance

```cpp
// Base class
class Instrument {
private:
    string type_;

public:
    Instrument(string t) : type_(t) {
        cout << "Instrument constructor called\n";
    }

    // Copy constructor
    Instrument(const Instrument& other) : type_(other.type_) {
        cout << "Instrument copy constructor called\n";
    }

    // Assignment operator
    Instrument& operator=(const Instrument& other) {
        cout << "Instrument assignment operator called\n";
        if (this != &other) {
            type_ = other.type_;
        }
        return *this;
    }

    string getType() const { return type_; }
};

// Derived class
class Guitar : public Instrument {
private:
    int strings_;

public:
    Guitar(string t, int s) : Instrument(t), strings_(s) {
        cout << "Guitar constructor called\n";
    }

    // Copy constructor - must call base copy constructor
    Guitar(const Guitar& other)
        : Instrument(other), strings_(other.strings_) {
        cout << "Guitar copy constructor called\n";
    }

    // Assignment operator - must call base assignment
    Guitar& operator=(const Guitar& other) {
        cout << "Guitar assignment operator called\n";
        if (this != &other) {
            Instrument::operator=(other);  // Call base class assignment
            strings_ = other.strings_;
        }
        return *this;
    }

    int getStrings() const { return strings_; }
};
```

### Virtual Functions and Polymorphism

```cpp
// Base class with virtual function
class Animal {
private:
    string type_;

public:
    Animal(string t = "Animal") : type_(t) { }

    // Virtual destructor (IMPORTANT for polymorphism)
    virtual ~Animal() { }

    // Virtual function for polymorphic behavior
    virtual void speak() const {
        cout << "Animal sound" << endl;
    }

    string getType() const { return type_; }
};

// Derived class overriding virtual function
class Dog : public Animal {
public:
    Dog() : Animal("Dog") { }

    // Override keyword (C++11) - documents intent and catches errors
    void speak() const override {
        cout << "Woof woof, I'm a dog!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat() : Animal("Cat") { }

    void speak() const override {
        cout << "Meow, I'm a cat!" << endl;
    }
};

// Polymorphic function
void makeSound(const Animal* animal) {
    animal->speak();  // Calls appropriate version based on actual type
}

// Usage
int main() {
    Animal a;
    Dog d;
    Cat c;

    makeSound(&a);  // "Animal sound"
    makeSound(&d);  // "Woof woof, I'm a dog!"
    makeSound(&c);  // "Meow, I'm a cat!"

    return 0;
}
```

---

## Code Review Checklist

### Before Submitting
- [ ] Code compiles without errors or warnings
- [ ] Ran clang++ linter with `-Wall -Wextra`
- [ ] All functions have appropriate comments
- [ ] Memory management is correct (no leaks)
- [ ] Include guards present in all header files
- [ ] Const correctness applied
- [ ] Naming conventions followed
- [ ] No magic numbers (use named constants)
- [ ] Tested with sample inputs
- [ ] Code is readable and well-formatted

### Class Checklist
- [ ] Appropriate access specifiers (public/private)
- [ ] Constructor initialization lists used
- [ ] Big Three implemented if using dynamic memory
- [ ] Virtual destructor if class has virtual functions
- [ ] Const member functions marked correctly
- [ ] Member variables have descriptive names

### Function Checklist
- [ ] Single responsibility principle
- [ ] Appropriate parameter types (const reference for large objects)
- [ ] Clear return type
- [ ] Input validation where needed
- [ ] No unused variables
- [ ] Function length reasonable (<50 lines)

---

## Resources

- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [C++ Reference](https://en.cppreference.com/)
- [LearnCpp.com](https://www.learncpp.com/)

---

**Questions or Suggestions?**
This guide is a living document and will evolve as the course progresses. Consistency is key - follow these standards in all your code.
