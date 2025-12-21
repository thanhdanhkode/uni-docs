<!-- markdownlint-disable MD041 -->

## Program for Engineers (C) Note -- Basic

### Basic structure of a C program

```c
#include <stdio.h>
int main() {

  // Your code here...

  return 0;
}
```

The main() function is required for all C/C++ program, if missing its function, the program unable to run, the type of main() function is various, base on your choice, but to make it simple, use type `int` for most case

### Declare the variable

Basic format `type name = value;`

```c
int x = 1;
```

Constant format `const type name = value;`

```c
const int x = 0;
```

The constant variable is a unchangeable variable, read-only variable in a program

### Variable Type

| Type                   | Size (bytes)                  | Format Specifier |
| ---------------------- | ----------------------------- | ---------------- |
| int                    | at least 2, usually 4         | %d, %i           |
| char                   | 1                             | %c               |
| float                  | 4                             | %f               |
| double                 | 8                             | %lf              |
| short int              | 2 usually                     | %hd              |
| unsigned int           | at least 2, usually 4         | %u               |
| long int               | at least 4, usually 8         | %ld, %li         |
| long long int          | at least 8                    | %lld, %lli       |
| unsigned long int      | at least 4                    | %lu              |
| unsigned long long int | at least 8                    | %llu             |
| signed char            | 1                             | %c               |
| unsigned char          | 1                             | %c               |
| long double            | at least 10, usually 12 or 16 | %Lf              |

```c
int x = 0;
char a = 'A';
float y = 0.001;
double z = 0.001;
short int t = 0;
unsigned int u;
long int o = 5646;
long long int p;
unsigned long int e;
unsigned long long int r;
signed char g;
unsigned char g;
long long double l = 0.001e-3;
```

### Comment

For comment, use `//` for single line or use `/* */` for comment block or multiple line comments

```c
// Single comment line
/*
A Comment block
with multiple line of comments
*/
```

### Escape Sequence

| Escape Sequences | Character             |
| ---------------- | --------------------- |
| \b               | Backspace             |
| \f               | Form feed             |
| \n               | Newline               |
| \r               | Return                |
| \t               | Horizontal tab        |
| \v               | Vertical tab          |
| \\               | Backslash             |
| \'               | Single quotation mark |
| \"               | Double quotation mark |
| \?               | Question mark         |
| \0               | Null character        |
