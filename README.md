# printf

This project is a custom implementation of the C standard library function `printf`.  
The function is named `_printf` and mimics the behavior of `printf` for the supported conversion specifiers.

---

## Requirements
- Compilation will be done on **Ubuntu 20.04 LTS** with:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c


0. Basic conversion specifiers

Implement _printf handling:

%c → print a character

%s → print a string

%% → print a literal percent sign

1. Integers

Extend _printf to handle:

%d → print a decimal number

%i → print an integer

2. Man page

Create a manual page man_3_printf describing:

Function prototype

Description

Return value

Supported specifiers

Examples
## 👥 Team Collaboration

This project was completed by **Abdullah** and **Fahad** as part of the Holberton School curriculum.

### Task Contributions:

- **Abdullah**  
  - Implemented Task 0: Basic format specifiers (`%c`, `%s`, `%%`)  
  - Co-authored the manual page (`man_3_printf`)

- **Fahad**  
  - Implemented Task 1: Integer specifiers (`%d`, `%i`)  
  - Co-authored the manual page (`man_3_printf`)

We worked together on writing and formatting the `man_3_printf` documentation file.
