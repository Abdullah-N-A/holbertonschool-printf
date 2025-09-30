#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a single character
 * @args: va_list containing the character
 * Return: 1 (number of chars printed)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string
 * Return: number of chars printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
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
 * _printf - custom printf function supporting %c, %s, %%
 * @format: format string containing specifiers
 * Return: number of characters printed, -1 if error
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
			{
				va_end(args);
				return (-1);
			}

			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}

