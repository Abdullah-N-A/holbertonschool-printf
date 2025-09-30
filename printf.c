#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
			{
				va_end(args);
				return (-1);
			}
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (*s)
				{
					write(1, s++, 1);
					count++;
				}
			}
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
