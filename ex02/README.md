# CPP_08 Exercise 02 - MutantStack Error Analysis

## Overview

This document analyzes the compilation and runtime errors encountered in the MutantStack implementation for CPP Module 08, Exercise 02.

## Project Structure

```
ex02/
├── Makefile
├── include/
│   └── MutantStack.hpp
├── lib/
│   └── MutantStack.tpp
├── src/
│   └── main.cpp
└── README.md (this file)
```

## Error Categories

### 1. Compilation Errors (Initial Build)

#### Missing Header Includes

**Error:**

```
error: 'stack' in namespace 'std' does not name a template type
note: 'std::stack' is defined in header '<stack>'; did you forget to '#include <stack>'?
```

**Root Cause:**

- Missing `#include <stack>` in both `MutantStack.hpp` and `main.cpp`
- The compiler cannot recognize `std::stack<T>` without the proper header

**Files Affected:**

- `include/MutantStack.hpp` - Line 6: `class MutantStack : public std::stack<T>`
- `src/main.cpp` - Line 23: `std::stack<int> s(mstack);`

#### Template Syntax Errors

**Error:**

```
error: expected template-name before '<' token
error: expected '{' before '<' token
error: invalid use of incomplete type 'class MutantStack<T>'
```

**Root Cause:**

- The class definition was incomplete due to missing `#include <stack>`
- Template inheritance syntax requires the base class to be fully defined

### 2. Template Implementation Errors

#### Iterator Type Recognition

**Error:**

```
error: 'MutantStack<T>::iterator' is not a type
error: ISO C++ forbids declaration of 'iterator' with no type
error: invalid use of template-name 'MutantStack' without an argument list
```

**Root Cause:**

- Template class not properly defined due to missing base class
- Forward declarations failing because of incomplete type information

#### Parameter Template Deduction

**Error:**

```
error: invalid use of template-name 'MutantStack' without an argument list
note: class template argument deduction is only available with '-std=c++17' or '-std=gnu++17'
```

**Root Cause:**

- Using C++98 standard which requires explicit template parameters
- Missing template argument `<T>` in copy constructor parameter

### 3. Runtime Error (AddressSanitizer)

#### Segmentation Fault Details

```
AddressSanitizer:DEADLYSIGNAL
=================================================================
==11183==ERROR: AddressSanitizer: SEGV on unknown address
(pc 0x6072bafb3afa bp 0x7ffe0f786d70 sp 0x7ffe0f786b40 T0)
==11183==The signal is caused by a READ memory access.
==11183==Hint: this fault was caused by a dereference of a high value address
    #0 0x6072bafb3afa in main src/main.cpp:20
    #1 0x7d5d7122a1c9 in __libc_start_call_main
    #2 0x7d5d7122a28a in __libc_start_main_impl
    #3 0x6072bafb3444 in _start
```

**Critical Line:** `src/main.cpp:20` - `std::cout << *it << std::endl;`

#### Root Cause Analysis

**Iterator Implementation Issues:**

1. **Incorrect Comparison Operators:**

   ```cpp
   // WRONG - Compares object addresses, not iterator positions
   bool operator!=(const iterator &src) const {
       return this != &src;  // Should be: _it != src._it
   }

   bool operator==(const iterator &src) const {
       return this == &src;  // Should be: _it == src._it
   }
   ```

2. **Uninitialized Iterator Constructor:**

   ```cpp
   // PROBLEMATIC - NULL initialization for iterator
   iterator() : _it(NULL) {}  // Should be: _it() {}
   ```

3. **Incorrect Increment/Decrement:**

   ```cpp
   // INCOMPLETE - Not actually moving the iterator
   iterator &operator++() {
       return *this;  // Should be: ++_it; return *this;
   }
   ```

4. **Invalid Dereference Implementation:**
   ```cpp
   // WRONG - Accessing non-existent member
   T &operator*() {
       return this->_it.pointer;  // Should be: return *_it;
   }
   ```

#### Memory Access Pattern

1. **Stack Iterator Behavior:**

   - `std::stack` uses `std::deque` as default underlying container
   - Iterator access is through `this->c.begin()` and `this->c.end()`
   - The `c` member is the protected container in `std::stack`

2. **Segfault Sequence:**
   ```cpp
   MutantStack<int>::iterator it = mstack.begin();   // Gets iterator
   MutantStack<int>::iterator ite = mstack.end();    // Gets end iterator
   ++it;  // Calls broken operator++ (does nothing)
   --it;  // Calls broken operator-- (does nothing)
   while (it != ite) {  // Broken comparison (always true if objects differ)
       std::cout << *it << std::endl;  // Dereferences invalid memory
       ++it;  // Still does nothing - infinite loop with bad memory access
   }
   ```

### 4. Logical Implementation Errors

#### Assignment Operator

**Current Implementation:**

```cpp
MutantStack &operator=(const MutantStack &src) {
    if (this != &src) {
        (void)src;  // Does nothing - doesn't copy data
    }
    return *this;
}
```

**Issue:** No actual copying of data occurs

#### Iterator Loop Logic

**Problem:** With broken comparison operators, the loop condition `it != ite` may never be false, causing infinite iteration over invalid memory.

## Platform Differences

### Why It Works on Mac but Not Linux

1. **Different Memory Layout:** macOS and Linux have different memory management and layout strategies
2. **Compiler Differences:** Different default optimizations and error handling
3. **AddressSanitizer Availability:** Linux build might have AddressSanitizer enabled while Mac build doesn't
4. **Undefined Behavior Manifestation:** The broken iterator code exhibits undefined behavior that might "work" on one platform but crash on another

## Summary of Required Fixes

1. **Add Missing Headers:**

   - `#include <stack>` in `MutantStack.hpp`
   - `#include <stack>` in `main.cpp`

2. **Fix Iterator Implementation:**

   - Correct comparison operators to compare `_it` values
   - Fix increment/decrement operators to actually move iterator
   - Fix dereference operator to return `*_it`
   - Initialize default constructor properly

3. **Fix Assignment Operator:**

   - Call base class assignment operator: `std::stack<T>::operator=(src)`

4. **Template Syntax:**
   - Ensure all template parameters are properly specified

## Testing Recommendations

1. **Compile with Debug Flags:**

   ```bash
   g++ -g -fsanitize=address -Wall -Wextra -Werror -std=c++98
   ```

2. **Use Valgrind (if available):**

   ```bash
   valgrind --tool=memcheck --leak-check=full ./program
   ```

3. **Test with Simple Cases:**
   - Single element iteration
   - Empty stack iteration
   - Copy construction testing

## Notes

This error analysis demonstrates the importance of:

- Proper template class implementation
- Correct iterator semantics
- Platform-independent code testing
- Understanding undefined behavior in C++
