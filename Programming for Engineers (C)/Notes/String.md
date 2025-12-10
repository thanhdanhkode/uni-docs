<!-- markdownlint-disable MD041 -->

## Program for Engineers (C) Note -- Strings

### String & character function reference

Below is a concise reference for common C string and character functions (prototype + short description).

| Function | Prototype                                                          | Description                                                                                     |
| -------- | ------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------- |
| isdigit  | `int isdigit(int c)`                                               | Returns non-zero if `c` is a decimal digit (0-9).                                               |
| isalpha  | `int isalpha(int c)`                                               | Returns non-zero if `c` is an alphabetic letter (A-Z, a-z).                                     |
| isalnum  | `int isalnum(int c)`                                               | Returns non-zero if `c` is alphanumeric (letter or digit).                                      |
| isxdigit | `int isxdigit(int c)`                                              | Returns non-zero if `c` is a hexadecimal digit (0-9, A-F, a-f).                                 |
| islower  | `int islower(int c)`                                               | Returns non-zero if `c` is a lowercase letter.                                                  |
| isupper  | `int isupper(int c)`                                               | Returns non-zero if `c` is an uppercase letter.                                                 |
| tolower  | `int tolower(int c)`                                               | Converts uppercase letter to lowercase; returns converted value.                                |
| toupper  | `int toupper(int c)`                                               | Converts lowercase letter to uppercase; returns converted value.                                |
| isspace  | `int isspace(int c)`                                               | Returns non-zero for white-space characters (space, tab, newline, etc.).                        |
| iscntrl  | `int iscntrl(int c)`                                               | Tests for control characters.                                                                   |
| ispunct  | `int ispunct(int c)`                                               | Tests for punctuation characters.                                                               |
| isprint  | `int isprint(int c)`                                               | Tests for any printable character including space.                                              |
| isgraph  | `int isgraph(int c)`                                               | Tests for any printable character except space.                                                 |
| strtod   | `double strtod(const char *nptr, char **endptr)`                   | Converts initial part of string to `double`; `endptr` points after parsed text.                 |
| strtol   | `long strtol(const char *nptr, char **endptr, int base)`           | Converts string to `long` using `base`; use `endptr` and `errno` to detect errors.              |
| strtoul  | `unsigned long strtoul(const char *nptr, char **endptr, int base)` | Converts string to `unsigned long`.                                                             |
| fgets    | `char *fgets(char *s, int size, FILE *stream)`                     | Reads a line (including spaces) into `s`, up to `size-1` chars; returns `s` or `NULL`.          |
| putchar  | `int putchar(int c)`                                               | Writes character `c` (converted to `unsigned char`) to `stdout`; returns written char or `EOF`. |
| getchar  | `int getchar(void)`                                                | Reads next character from `stdin` (returns `EOF` on end/error).                                 |
| sprintf  | `int sprintf(char *str, const char *format, ...)`                  | Formats output into `str` (unsafe if buffer too small). Use `snprintf` to limit size.           |
| snprintf | `int snprintf(char *str, size_t size, const char *format, ...)`    | Writes formatted data to `str` with limit `size`.                                               |
| sscanf   | `int sscanf(const char *str, const char *format, ...)`             | Reads formatted data from string `str`.                                                         |
| strcpy   | `char *strcpy(char *dest, const char *src)`                        | Copies NUL-terminated `src` into `dest` (dest must be large enough).                            |
| strncpy  | `char *strncpy(char *dest, const char *src, size_t n)`             | Copies up to `n` chars from `src` to `dest` (may not NUL-terminate).                            |
| strcat   | `char *strcat(char *dest, const char *src)`                        | Appends `src` to `dest` (dest must have enough space).                                          |
| strncat  | `char *strncat(char *dest, const char *src, size_t n)`             | Appends at most `n` chars from `src` to `dest`.                                                 |
| strcmp   | `int strcmp(const char *s1, const char *s2)`                       | Compares two strings lexicographically; returns <0, 0, >0.                                      |
| strncmp  | `int strncmp(const char *s1, const char *s2, size_t n)`            | Compares up to `n` chars of two strings.                                                        |
| strchr   | `char *strchr(const char *s, int c)`                               | Returns pointer to first occurrence of `c` in `s`, or `NULL`.                                   |
| strrchr  | `char *strrchr(const char *s, int c)`                              | Returns pointer to last occurrence of `c` in `s`, or `NULL`.                                    |
| strcspn  | `size_t strcspn(const char *s, const char *reject)`                | Returns length of initial segment of `s` containing no chars from `reject`.                     |
| strspn   | `size_t strspn(const char *s, const char *accept)`                 | Returns length of initial segment of `s` consisting only of chars in `accept`.                  |
| strpbrk  | `char *strpbrk(const char *s, const char *accept)`                 | Returns pointer to first occurrence in `s` of any char from `accept`, or `NULL`.                |
| strstr   | `char *strstr(const char *haystack, const char *needle)`           | Finds first occurrence of substring `needle` in `haystack`; returns pointer or `NULL`.          |
| strtok   | `char *strtok(char *str, const char *delim)`                       | Tokenizes `str` into tokens separated by `delim` (not thread-safe).                             |
| memcpy   | `void *memcpy(void *dest, const void *src, size_t n)`              | Copies `n` bytes from `src` to `dest` (undefined if regions overlap).                           |
| memmove  | `void *memmove(void *dest, const void *src, size_t n)`             | Copies `n` bytes safely even if regions overlap.                                                |
| memchr   | `void *memchr(const void *s, int c, size_t n)`                     | Scans `n` bytes for character `c`; returns pointer or `NULL`.                                   |
| memset   | `void *memset(void *s, int c, size_t n)`                           | Fills `n` bytes of `s` with value `c` (as unsigned char).                                       |
| strerror | `char *strerror(int errnum)`                                       | Returns pointer to a human-readable string describing `errnum`.                                 |
| strlen   | `size_t strlen(const char *s)`                                     | Returns length of `s` excluding the terminating NUL.                                            |
| memcmp   | `int memcmp(const void *s1, const void *s2, size_t n)`             | Compares `n` bytes of memory; returns <0,0,>0.                                                  |

Notes:

- Prefer `snprintf` over `sprintf` to avoid buffer overruns.
- Use `strtol`/`strtod` with `endptr` and `errno` for safe numeric conversions.
- For tokenization in reentrant code, use `strtok_r` (POSIX) or `strtok_s` (MSVC).
