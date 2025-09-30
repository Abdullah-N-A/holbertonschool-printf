#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* _printf function */
int _printf(const char *format, ...);

/* Helper functions for _printf */
int print_char(char c);
int print_string(char *s);

#endif /* MAIN_H */
