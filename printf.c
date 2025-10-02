#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a single character
 * @c: character to print
 * Return: 1 (number of characters printed)
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @s: string to print
 * Return: number of characters printed
 */
int print_string(char *s)
{
	int count = 0;

	if (!s)
		s = "(null)";

	while (*s)
	{
		write(1, s++, 1);
		count++;
	}

	return (count);
}

/**
 * _printf - prints characters, strings, and percent signs
 * @format: format string containing specifiers
 * Return: number of characters printed, -1 on error
 */
int _printf(const char *format, ...)
{
        va_list args;
        int i = 0, count = 0;

        if (!format)
                return (-1);

        va_start(args, format);

        while (format[i])
        {
                if (format[i] == '%')
                {
                        i++;
                        if (!format[i])
                                return (va_end(args), -1);

                        if (format[i] == 'c')
                                count += print_char(va_arg(args, int));
                        else if (format[i] == 's')
                                count += print_string(va_arg(args, char *));
                        else if (format[i] == 'd' || format[i] == 'i')
                                count += print_int(va_arg(args, int));
                        else if (format[i] == 'b')
                                count += print_binary(va_arg(args, unsigned int));
                        else if (format[i] == 'u')
                                count += print_unsigned(va_arg(args, unsigned int));
                        else if (format[i] == 'o')
                                count += print_octal(va_arg(args, unsigned int));
                        else if (format[i] == 'x')
                                count += print_hex(va_arg(args, unsigned int), 0); /* lowercase */
                        else if (format[i] == 'X')
                                count += print_hex(va_arg(args, unsigned int), 1);  /* UPPERCASE */
                        else if (format[i] == '%')
                                count += print_char('%');
                        else
                        {
                                count += print_char('%');
                                count += print_char(format[i]);
                        }
                }
                else
                        count += print_char(format[i]);

                i++;
        }

        va_end(args);
        return (count);
}
