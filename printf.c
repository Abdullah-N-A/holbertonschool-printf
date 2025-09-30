#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: character string with format specifiers
 *
 * Return: number of characters printed (excluding '\0'),
 *         or -1 if error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *s;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i]) /* handle case of % at end */
				return (-1);

			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (*s)
				{
					write(1, s, 1);
					s++;
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
