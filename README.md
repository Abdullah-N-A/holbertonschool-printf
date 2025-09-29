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
