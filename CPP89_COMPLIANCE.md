# C++89 Compliance Documentation

This project demonstrates strict adherence to 42 curriculum rules and C++89 standard.

## Compliance Features Implemented

### ✅ Required Conventions

#### 1. Class Naming Convention
- **Rule**: UpperCamelCase for class names
- **Implementation**: `SampleClass` (not `sampleClass` or `sample_class`)

#### 2. Function and Variable Naming
- **Rule**: Detailed, self-explanatory names following single responsibility principle
- **Examples**:
  - `getPrivateIntegerValue()` instead of `getValue()`
  - `setPrivateStringValue()` instead of `setString()`
  - `isIntegerValuePositive()` instead of `isPositive()`
  - `resetInstanceToDefaultValues()` instead of `reset()`
  - `displayInstanceInformation()` instead of `print()`

#### 3. Function Implementation Location
- **Rule**: All function implementations in .cpp files (not in headers)
- **Implementation**: 
  - `SampleClass.hpp` contains only declarations
  - `SampleClass.cpp` contains all function implementations

#### 4. Orthodox Canonical Form
- **Rule**: Required by 42 for all classes
- **Implementation**: Default constructor, copy constructor, assignment operator, destructor

### ✅ Prohibited Features (Successfully Avoided)

#### 1. C++11+ Features
- ❌ No `auto` keyword
- ❌ No range-based for loops (`for(auto& item : container)`)
- ❌ No lambda expressions
- ❌ No nullptr (using NULL or 0 instead)
- ❌ No initializer lists beyond member initialization

#### 2. Prohibited Libraries and Functions
- ❌ No Boost library usage
- ❌ No printf, malloc, calloc, realloc, free functions
- ❌ No standard library containers (vector, map, list, set, etc.)
- ❌ No standard library algorithms

#### 3. Prohibited Language Features
- ❌ No `friend` keyword
- ❌ No `using namespace` directives (even `using namespace std`)

### ✅ C++89 Standard Compliance

#### 1. Compilation Flags
```makefile
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

#### 2. Member Initialization
- Using initialization lists in constructors (C++89 compliant)
- Explicit member initialization in copy constructor and assignment operator

#### 3. Const Correctness
- Getter methods marked as `const`
- Const reference parameters where appropriate
- Proper const member function design

## Code Structure

```
cpp-module/
├── SampleClass.hpp     # Header with declarations only
├── SampleClass.cpp     # Implementation file
├── main.cpp           # Test program
├── Makefile          # C++89 compliant build system
└── README.md         # This documentation
```

## Building and Testing

```bash
# Check C++89 compliance
make check

# Compile the program
make

# Run tests
make test

# Clean build artifacts
make clean
```

## Single Responsibility Principle Examples

Each function has exactly one responsibility:

- `getPrivateIntegerValue()`: Only retrieves the integer value
- `setPrivateIntegerValue()`: Only sets the integer value  
- `isIntegerValuePositive()`: Only checks if integer is positive
- `isStringValueEmpty()`: Only checks if string is empty
- `displayInstanceInformation()`: Only displays object state
- `resetInstanceToDefaultValues()`: Only resets object to defaults

## Memory Management

- No dynamic memory allocation used (avoiding malloc/free requirement)
- All objects use stack allocation
- Proper destructor implementation for resource cleanup
- Safe copy semantics with deep copying where needed

This implementation serves as a reference for C++89 compliant code following 42 curriculum standards.