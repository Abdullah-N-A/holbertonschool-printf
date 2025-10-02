#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* _printf function */
int _printf(const char *format, ...);

/* Helper functions for _printf */
int print_char(char c);
int print_string(char *s);

int print_int(int n);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
#endif
