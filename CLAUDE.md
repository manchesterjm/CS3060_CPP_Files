# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a CS3060 C++ Programming course repository containing in-class exercises, assignments, and final exam problems. The codebase demonstrates progressive learning of C++ concepts from basic I/O to advanced OOP features.

**Repository**: https://github.com/manchesterjm/CS3060_CPP_Files
**Maintainer**: Josh Manchester (manchesterjm@gmail.com)

### Repository Status
- ✅ All 26 .cpp files pass clang++ linting with `-Wall -Wextra`
- ✅ All files follow PascalCase naming conventions
- ✅ Comprehensive style guide applied (see STYLE_GUIDE.md)
- ✅ No compiled executables in repository

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

**Linter**: clang++ version 18.1.3 (installed in WSL Ubuntu)

Use clang++ for linting C++ code:

```bash
# Check a single file for issues
wsl bash -c "clang++ -std=c++11 -Wall -Wextra -fsyntax-only In_Class/filename.cpp"

# Lint all files
cd In_Class && for f in *.cpp; do wsl bash -c "clang++ -std=c++11 -Wall -Wextra -fsyntax-only '$f'"; done

# For files with headers, include them in the command
wsl bash -c "clang++ -std=c++11 -Wall -Wextra -fsyntax-only In_Class/TestScores.cpp"
```

Common flags:
- `-Wall -Wextra` - Enable comprehensive warnings
- `-fsyntax-only` - Check syntax without compiling
- `-std=c++11` - Use C++11 standard (matches course requirements)

**Note**: All files in this repository currently pass linting with zero warnings.

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
- File: `ArraySizeDemo.cpp` demonstrates array basics
- Files: `MonkeyBusiness.cpp`, `SalsaSales.cpp` show 2D arrays and data processing

**Object-Oriented Programming**
- Class design with constructors, getters/setters
- Separation of interface (`.h`) and implementation (`.cpp`)
- Example: `TestScores.h` / `TestScores.cpp` demonstrate class structure

**Operator Overloading**
- Member function overloading for same-type operations
- Friend functions for mixed-type operations (e.g., `int + Rational`)
- Files: `RationalNumber.cpp` shows both approaches, `RationalAdvanced.cpp` shows complete implementation

**Inheritance and Polymorphism**
- Single inheritance with base/derived classes
- Copy constructors and assignment operators in inheritance hierarchies
- Virtual functions and runtime polymorphism
- Files:
  - `InheritanceBigThree.cpp` - Big Three in inheritance hierarchies
  - `AnimalPolymorphism.cpp` - Virtual functions and dynamic dispatch
  - `ShapeInheritance.cpp` - Shape hierarchy with constructors
  - `VirtualCircle.cpp`, `VirtualComparison.cpp` - Virtual vs non-virtual comparison
  - `AbstractAppliance.cpp` - Abstract base classes and pure virtual functions

**Exception Handling**
- Custom exception classes
- Try-catch blocks with proper exception propagation
- Files: `TestScores.cpp`, `NegativeScore.h` demonstrate exception design

**Final Exam Topics**
- `CarClass.cpp` - Complete class implementation (Final 13.3)
- `EmployeeProduction.cpp` - Inheritance with Employee/ProductionWorker classes (Final 15.1)

**Templates and Advanced Topics**
- `FunctionTemplates.cpp` - Generic programming with templates
- `ComplexNumber.cpp` - Complex number class with getters/setters

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
- Member variables use trailing underscore convention: `count_`, `name_`, `speed_`
- Comments explain intent and learning objectives
- Some files contain planning comments at the bottom showing problem-solving approach

## File Reference

For a complete mapping of old date-based filenames to new descriptive names, see `FILE_RENAME_MAP.md`.

**Key files by topic:**
- **Basic I/O**: `BasicIO.cpp`, `TempConverter.cpp`, `KineticEnergy.cpp`
- **Arrays**: `ArraySizeDemo.cpp`, `ArrayMode.cpp`, `ArrayMedian.cpp`
- **Structs**: `RectangleStruct.cpp`, `VendingMachine.cpp`, `InventoryBins.cpp`
- **Classes**: `CarClass.cpp`, `ComplexNumber.cpp`, `TestScores.cpp`
- **Inheritance**: `InheritanceBigThree.cpp`, `EmployeeProduction.cpp`, `ShapeInheritance.cpp`
- **Polymorphism**: `AnimalPolymorphism.cpp`, `VirtualCircle.cpp`, `AbstractAppliance.cpp`
- **Operator Overloading**: `RationalNumber.cpp`, `RationalAdvanced.cpp`
- **Projects**: `MonkeyBusiness.cpp`, `SalsaSales.cpp`, `SearchComparison.cpp`

## Git Workflow

```bash
# Make changes to files
# ... edit files ...

# Stage and commit
git add .
git commit -m "Description of changes"

# Push to GitHub
git push origin main
```

## Additional Resources

- **STYLE_GUIDE.md** - Comprehensive C++ coding standards for this repository
- **FILE_RENAME_MAP.md** - Reference for old → new filename mappings
- **.gitignore** - Configured to exclude compiled executables and IDE files
