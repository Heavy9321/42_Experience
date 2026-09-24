*This project has been created as part of the 42 curriculum by kasen.*

# ft_printf

## Description

`ft_printf` is a C library that recreates a subset of the standard `printf` function. It writes formatted output to standard output and returns the number of characters written. The project focuses on variadic arguments, parsing format strings, and converting values to decimal and hexadecimal text.

The mandatory conversions are:

| Specifier | Output |
| --- | --- |
| `%c` | A character |
| `%s` | A string |
| `%p` | A pointer in hexadecimal |
| `%d`, `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x`, `%X` | An unsigned hexadecimal integer in lowercase or uppercase |
| `%%` | A literal percent sign |

The required public interface is declared in `ft_printf.h`:

```c
int ft_printf(const char *format, ...);
```

## Instructions

From the project root, build the static library with:

```sh
make
```

This produces `libftprintf.a`. The Makefile should compile with `cc -Wall -Wextra -Werror` and provide `all`, `clean`, `fclean`, and `re` targets.

## Algorithm and data structures

A straightforward implementation walks the format string one character at a time. Ordinary characters are written directly. When it finds `%`, it reads the next conversion character and dispatches to a helper for that argument type. `va_list` holds the variable arguments; `va_start`, `va_arg`, and `va_end` manage access to them.

Integer helpers convert values by repeatedly taking remainders in base 10 or 16, then emitting digits in the correct order. A digit alphabet such as `0123456789abcdef` or `0123456789ABCDEF` handles hexadecimal case. Signed decimals need special care for the smallest representable integer; converting the magnitude through a wider or unsigned type avoids negating it in its original signed type. Pointer output uses a suitable unsigned integer type for the address and a hexadecimal prefix.

Only the format position, argument list, digit alphabet, and running character count need to be tracked. This keeps the mandatory implementation small and avoids building a copy of the original `printf` output buffer. Each helper should report its written character count so the top-level function can return the total. Adapt this section to match the actual code if you choose a different approach.

## Resources

- [`printf(3)`](https://man7.org/linux/man-pages/man3/printf.3.html) — format syntax, conversions, and return value.
- [`stdarg(3)`](https://man7.org/linux/man-pages/man3/stdarg.3.html) — handling variadic arguments with `va_list`.
- [`write(2)`](https://man7.org/linux/man-pages/man2/write.2.html) — writing bytes to a file descriptor.
- The supplied **ft_printf** subject (version 12.1) — project scope and submission requirements.

**AI usage:** AI helped draft and organize this README from the project subject. The description of the algorithm is a suggested design; verify and revise it against your implementation before submission. This README does not claim AI was used to write or test the C source code.
