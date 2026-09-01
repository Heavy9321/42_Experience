*This project has been created as part of the 42 curriculum by kasen.*

## Description

Libft is the first project in the 42 school curriculum. The objective of this project is to reimplement a subset of standard C library (`libc`) functions along with additional utility functions for memory management, string manipulation, and linked list handling.

Creating this library helps to understand the underlying mechanics of standard C functions, pointer arithmetic, dynamic memory allocation on the heap, and data structures. The compiled archive `libft.a` serves as a core utility library for future C projects in the 42 curriculum.

---

## Detailed Description of the Library

The library contains three main sections:

### Part 1: Libc Functions

Standard C library functions reimplemented from scratch according to their respective manual pages:

- **Character Classification & Conversion:**
  - `ft_isalpha` - Checks for an alphabetic character.
  - `ft_isdigit` - Checks for a digit (0 through 9).
  - `ft_isalnum` - Checks for an alphanumeric character.
  - `ft_isascii` - Checks whether a character fits into the ASCII character set.
  - `ft_isprint` - Checks for any printable character.
  - `ft_toupper` - Converts a lower-case letter to uppercase.
  - `ft_tolower` - Converts an upper-case letter to lowercase.

- **String Manipulation:**
  - `ft_strlen` - Computes the length of a string.
  - `ft_strchr` - Locates the first occurrence of a character in a string.
  - `ft_strrchr` - Locates the last occurrence of a character in a string.
  - `ft_strncmp` - Compares two strings up to `n` bytes.
  - `ft_strnstr` - Locates a substring in a string with a length limit.
  - `ft_strlcpy` - Copies a string with size bounded protection.
  - `ft_strlcat` - Concatenates a string with size bounded protection.
  - `ft_strdup` - Duplicates a string using dynamic memory allocation (`malloc`).

- **Memory Management:**
  - `ft_memset` - Fills a block of memory with a specific byte value.
  - `ft_bzero` - Sets all bytes in a memory block to zero (`\0`).
  - `ft_memcpy` - Copies a specified number of bytes from one memory area to another.
  - `ft_memmove` - Copies memory area handling overlapping regions safely.
  - `ft_memchr` - Scans a memory block for a specific byte.
  - `ft_memcmp` - Compares two memory blocks byte by byte.
  - `ft_calloc` - Allocates memory dynamically and initializes all bytes to zero.

- **Conversions:**
  - `ft_atoi` - Converts an ASCII string representation of a number to an `int`.

---

### Part 2: Additional Functions

Custom helper functions extending basic operations:

- `ft_substr` - Allocates and returns a substring from a given string.
- `ft_strjoin` - Concatenates two strings into a newly allocated string.
- `ft_strtrim` - Trims leading and trailing characters specified in a set from a string.
- `ft_split` - Splits a string into an array of substrings using a delimiter character.
- `ft_itoa` - Converts an integer into a null-terminated string.
- `ft_strmapi` - Creates a new string by applying a function to each character of an existing string.
- `ft_striteri` - Applies a function to each character of a string in-place with its index.
- `ft_putchar_fd` - Outputs a character to a specified file descriptor.
- `ft_putstr_fd` - Outputs a string to a specified file descriptor.
- `ft_putendl_fd` - Outputs a string followed by a newline to a specified file descriptor.
- `ft_putnbr_fd` - Outputs an integer to a specified file descriptor.

---

### Part 3: Linked List Functions

Functions for manipulating singly linked lists using the `t_list` structure:

- `ft_lstnew` - Allocates and returns a new list node.
- `ft_lstadd_front` - Adds a new node at the beginning of a list.
- `ft_lstsize` - Counts the number of nodes in a list.
- `ft_lstlast` - Returns the last node of a list.
- `ft_lstadd_back` - Adds a new node at the end of a list.
- `ft_lstdelone` - Frees the content of a node and the node itself.
- `ft_lstclear` - Deletes and frees an entire list.
- `ft_lstiter` - Applies a given function to the content of all nodes in a list.
- `ft_lstmap` - Iterates over a list, applies a function to each content, and creates a new list.

---

## Instructions

### Compilation

Compile the static library `libft.a` using the provided `Makefile` with `cc` and the mandatory compilation flags (`-Wall -Wextra -Werror`):

```bash
# Compile mandatory functions into libft.a
make
# or: make all

# Remove object files (.o)
make clean

# Remove object files and the libft.a library
make fclean

# Perform a full clean re-compilation
make re
```

---

## Resources

### 1. References & Documentation

- **GeeksforGeeks (C Programming Language):** https://www.geeksforgeeks.org/c-programming-language/ — Consulted for theoretical foundations of dynamic memory allocation, pointer manipulation, and singly linked list algorithms.
- **cppreference.com (C Standard Library):** https://en.cppreference.com/w/c — Used to inspect exact function prototypes, boundary constraints, and standard return behaviors of `libc` routines.
- **Linux Programmer's Manual (Man Pages):** Standard system documentation (`man 3 malloc`, `man 3 memset`, `man 3 memmove`, `man 3 strchr`) used to ensure exact behavior matching with native Unix functions.
- **BSD Library Documentation:** Consulted for non-standard `glibc` routines like `strlcpy` and `strlcat` to adhere to BSD size-bounded string conventions.

### 2. AI Usage

In compliance with the 42 AI usage and transparency guidelines:

- **Documentation Structuring:** AI was utilized to format and organize the `README.md` file according to the mandatory requirements in Chapter V of the subject.
- **Conceptual & Edge-Case Analysis:** AI was prompted for theoretical edge-case scenarios, specifically:
  - Validating double-pointer cleanup mechanics during allocation failures in `ft_split`.
  - Analyzing buffer overlap directions and pointer safety in `ft_memmove`.
- **Code Autonomy:** No direct code generation or copy-pasting was used for project source files. All function logic, memory handling, Makefile rules, and norm compliance were implemented, debugged, and tested independently.
