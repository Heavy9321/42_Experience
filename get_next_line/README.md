*This project has been created as part of the 42 curriculum by kasen.*

# get_next_line

## Description
The **get_next_line** project is a fundamental programming assignment in the 42 curriculum. The objective is to write a function in C that reads and returns a single line terminated by a newline character (`\n`) from a given file descriptor, or returns `NULL` when reaching the End of File (EOF) or encountering an error.

Repeated calls to `get_next_line()` read the text file line by line without losing the reading state between calls.

### Key Goals & Features
* **File I/O in C:** Direct use of POSIX system calls (`read`, `open`, `close`).
* **Static Variables:** Leveraging static storage to persist data (the "stash") across successive function calls.
* **Dynamic Memory Management:** Precise allocation and freeing of string buffers to guarantee zero memory leaks.
* **Variable Buffer Size:** Support for arbitrary `BUFFER_SIZE` values set at compile time (from `1` byte up to millions of bytes).
* **Bonus Implementation:** Simultaneous reading from multiple file descriptors using an indexed static array without losing reading context.

---

## Instructions

### Files Included
* **Mandatory:** `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`
* **Bonus:** `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h`

### Compilation
The project does not include a Makefile because it is intended to be integrated as a library or component inside other projects.

To compile with your test code (`main.c`), specify the compiler flags along with the required `BUFFER_SIZE` macro definition:

#### Mandatory Part:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

#### Bonus Part (Multiple File Descriptors):
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## Resources

### References & Documentation
* [POSIX read(2) Manual](https://man7.org/linux/man-pages/man2/read.2.html) — Details on return values, EOF, and error handling (`EBADF`, `EINTR`).
* [POSIX open(2) Manual](https://man7.org/linux/man-pages/man2/open.2.html) — Information regarding file flags (`O_RDONLY`, `O_WRONLY`).
* [The C Programming Language (Kernighan & Ritchie)](https://en.wikipedia.org/wiki/The_C_Programming_Language) — Chapter 4: Static variables and storage duration.

### Use of AI
AI assistance was utilized during this project for:
* **Testing & Formatting Analysis:** Diagnosing terminal display anomalies caused by files missing trailing newline characters at EOF.
* **Symbol Resolution:** Debugging linker errors related to function naming conventions in the bonus implementation.
* **Documentation:** Drafting and structuring this `README.md` file according to the 42 school specifications.