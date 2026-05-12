# C Technical Assessment - Pattern Generator

## Overview

A professional C implementation of a terminal-based pattern-drawing system with 5 different rectangular pattern generators. Each assignment implements the core `rush(int x, int y)` function with distinct character patterns while maintaining code reusability principles and professional development standards.

### Key Features

✅ **Code Reusability** - Shared `common/my_putchar.c` eliminates duplication  
✅ **Independent Compilability** - Each assignment compiles separately  
✅ **Professional Comments** - Well-documented for code review and maintainability  
✅ **Scalable Design** - Works correctly for all positive dimensions (1×1 to n×n)  
✅ **Robust Error Handling** - Validates input and reports errors to stderr  
✅ **System-Level Compliance** - Uses only `write()` for I/O operations  

---

## Repository Structure

```
TechTest/
├── README.md
├── common/
│   └── my_putchar.c              ← Shared utility (single source of truth)
├── rush-1-1/
│   ├── rush.c                    (Classic rectangle: o, -, |)
│   └── rush.h
├── rush-1-2/
│   ├── rush.c                    (Diamond corners: /, \)
│   └── rush.h
├── rush-1-3/
│   ├── rush.c                    (Alphabetic: A, B, C - vertical asymmetry)
│   └── rush.h
├── rush-1-4/
│   ├── rush.c                    (Alphabetic: A, C - horizontal symmetry)
│   └── rush.h
└── rush-1-5/
    ├── rush.c                    (Alphabetic: A, C - diagonal symmetry)
    └── rush.h
```

### Design Pattern: DRY Principle

The `my_putchar()` function is implemented once in `common/my_putchar.c` and reused across all 5 assignments. This eliminates code duplication while maintaining independent compilability for each assignment.

---


## Compilation Instructions

### Compile Individual Assignments

```bash
# Assignment 1
cc -Wall -Wextra -Werror rush-1-1/*.c common/my_putchar.c test_main.c -I rush-1-1 -o test1

# Assignment 2
cc -Wall -Wextra -Werror rush-1-2/*.c common/my_putchar.c test_main.c -I rush-1-2 -o test2

# Assignment 3
cc -Wall -Wextra -Werror rush-1-3/*.c common/my_putchar.c test_main.c -I rush-1-3 -o test3

# Assignment 4
cc -Wall -Wextra -Werror rush-1-4/*.c common/my_putchar.c test_main.c -I rush-1-4 -o test4

# Assignment 5
cc -Wall -Wextra -Werror rush-1-5/*.c common/my_putchar.c test_main.c -I rush-1-5 -o test5
```

### Sample test_main.c

```c
#include "rush.h"

int main(void)
{
    rush(5, 3);
    return (0);
}
```

---

## Code Reusability & Architecture

### Shared Component: `common/my_putchar.c`

```c
#include <unistd.h>

/*
** my_putchar - Outputs a single character to standard output
** @c: character to print
**
** Uses write() system call for maximum compatibility and control
** write(1, &c, 1) outputs 1 byte to file descriptor 1 (stdout)
** Shared implementation used across all rush assignments
*/
void my_putchar(char c)
{
    write(1, &c, 1);
}
```

**Benefits:**
- Single source of truth for character output
- Easy to modify output behavior globally
- Eliminates 5 duplicate implementations
- Follows DRY (Don't Repeat Yourself) principle
- Professional-grade code organization

---

## Implementation Details

### Algorithm Structure (All Assignments)

```
For each row (0 to y-1):
  For each column (0 to x-1):
    Determine character based on position:
      - Corners: specific (row, col) combinations
      - Edges: first/last row or first/last column
      - Interior: everything else is space
    Print character using my_putchar()
  Print newline after each row
```

### Time & Space Complexity

- **Time:** O(x·y) - must output x·y characters (optimal)
- **Space:** O(1) - only uses local variables
- **Scalability:** Works for any positive integer dimensions

### Error Handling

```c
if (x <= 0 || y <= 0)
{
    write(2, "Invalid size\n", 13);  /* Write to stderr (fd 2) */
    return;
}
```

Outputs "Invalid size\n" to stderr and exits immediately.

---

## Testing Results

All assignments tested and verified with:
- Edge cases: 1×1, 1×5, 5×1
- Standard sizes: 4×4, 5×3
- Large dimensions: 10×10, 15×15
- Error cases: (0,0), (-1,5), invalid inputs

✅ All tests pass without segmentation faults, bus errors, or floating point exceptions.

---

## Code Quality Standards

✅ **Compilation:** `-Wall -Wextra -Werror` (all warnings as errors)  
✅ **Comments:** Professional-grade documentation with function headers  
✅ **Naming:** Clear, descriptive variable and function names  
✅ **Style:** Consistent 4-space tab indentation  
✅ **No undefined behavior** - robust input validation  
✅ **Modular design** - reusable components  

---

## Professional Highlights

- **Code Reusability:** Implemented DRY principle with shared `my_putchar.c`
- **Maintainability:** Comprehensive inline comments explaining logic
- **Scalability:** Pattern logic works for any positive dimensions
- **Robustness:** Input validation and proper error handling
- **Industry Standards:** Follows professional C development practices
- **Independent Delivery:** Each assignment compiles separately while sharing common code