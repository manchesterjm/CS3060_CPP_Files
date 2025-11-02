# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a CS3060 C++ Programming course repository containing in-class exercises, assignments, and final exam problems. The codebase demonstrates progressive learning of C++ concepts from basic I/O to advanced OOP features.

## Building and Running C++ Files

The system has WSL Ubuntu with g++ compiler installed.

### Direct Compilation (Recommended)
```bash
# Compile a single file
wsl g++ -std=c++11 In_Class/filename.cpp -o output

# Run the executable
wsl ./output
```

### Using CMake
The repository includes a `CMakeLists.txt` file in the `In_Class/` directory:

```bash
wsl cmake -S In_Class -B build
wsl cmake --build build
wsl ./build/Assignment
```

Note: Update the `add_executable` line in `CMakeLists.txt` to specify which `.cpp` file to compile.

### Compiling Projects with Headers
For files that use custom headers (like `TestScores.cpp`):

```bash
# All related files must be compiled together
wsl g++ -std=c++11 In_Class/TestScores.cpp -o testscores
wsl ./testscores
```

## Linting and Static Analysis

Use clang for linting C++ code:

```bash
# Check a file for issues
wsl clang++ -std=c++11 -Wall -Wextra -fsyntax-only In_Class/filename.cpp

# For files with headers, check all related files
wsl clang++ -std=c++11 -Wall -Wextra -fsyntax-only In_Class/TestScores.cpp
```

Common flags:
- `-Wall -Wextra` - Enable comprehensive warnings
- `-fsyntax-only` - Check syntax without compiling
- `-std=c++11` - Use C++11 standard (matches course requirements)

## Code Architecture

### File Organization
- `In_Class/` - All course materials including exercises, assignments, and exam problems
- Files use descriptive PascalCase naming: `ClassName.cpp` or `DescriptiveName.cpp`
  - Examples: `KineticEnergy.cpp`, `RationalNumber.cpp`, `CarClass.cpp`
  - This improves code discoverability and follows C++ conventions
- Header files (`.h`) use include guards following pattern: `#ifndef HEADER_NAME_H`

### Key Programming Concepts Demonstrated

**Basic I/O and Functions** (Early exercises)
- Standard input/output with `cin`/`cout`
- Function declarations and definitions
- Basic data types and formatting (`iomanip`, `setprecision`)

**Data Structures**
- STL arrays (`std::array`) with size management
- Dynamic memory allocation with pointers
- File: `3_Feb_01.cpp` demonstrates array basics

**Object-Oriented Programming**
- Class design with constructors, getters/setters
- Separation of interface (`.h`) and implementation (`.cpp`)
- Example: `TestScores.h` / `TestScores.cpp` demonstrate class structure

**Operator Overloading**
- Member function overloading for same-type operations
- Friend functions for mixed-type operations (e.g., `int + Rational`)
- File: `9_apr_01.cpp` shows both approaches with the `Rational` class

**Inheritance and Polymorphism**
- Single inheritance with base/derived classes
- Copy constructors and assignment operators in inheritance hierarchies
- Virtual functions and runtime polymorphism
- Files: `21_Apr_01.cpp` (Big Three in inheritance), `21_Apr_02.cpp` (virtual functions)

**Exception Handling**
- Custom exception classes
- Try-catch blocks with proper exception propagation
- Files: `TestScores.cpp`, `NegativeScore.h` demonstrate exception design

**Final Exam Topics**
- `Final_13.3.cpp` - Complete class implementation with Big Three
- `Final_15.1.cpp` - Advanced class design patterns

## Common Patterns

### Class Design Template
Classes in this codebase typically follow this structure:
1. Private data members
2. Constructors (default and parameterized)
3. Getters (const member functions)
4. Setters (mutator functions)
5. Member functions for behavior

### Include Pattern
```cpp
#include <iostream>
#include <string>
#include <iomanip>  // for formatting
using namespace std;
```

### Exception Classes
Custom exceptions follow a simple pattern:
- Store the error information in private members
- Provide a constructor to capture the error context
- Provide getter methods to retrieve error details
- Use meaningful class names (e.g., `NegativeScore`)

## Development Notes

- Code uses `using namespace std;` throughout (common in educational contexts)
- Member initialization uses initializer lists (e.g., `Car(int y, string m) : yearModel(y), make(m), speed(0) {}`)
- Comments explain intent and learning objectives
- Some files contain planning comments at the bottom showing problem-solving approach
