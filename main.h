#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Auth: Your Name
 * Desc: Header file for custom _printf function
 *       Supports %c, %s, and %% specifiers.
 */

#include <stdarg.h>
#include <unistd.h>

/* Prototype for _printf */
int _printf(const char *format, ...);

/* Helper functions prototypes */
int print_char(va_list args);
int print_string(va_list args);

#endif /* MAIN_H */

