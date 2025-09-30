#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - simplified version of printf
 * @format: the string that may contain format specifiers
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *s;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i]) /* loop until end of string */
    {
        if (format[i] == '%') /* check for specifier */
        {
            i++;
            if (format[i] == 'c') /* %c -> print char */
            {
                char c = (char)va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 's') /* %s -> print string */
            {
                s = va_arg(args, char *);
                if (s == NULL)
                    s = "(null)";
                while (*s)
                {
                    write(1, s++, 1);
                    count++;
                }
            }
            else if (format[i] == '%') /* %% -> print % */
            {
                write(1, "%", 1);
                count++;
            }
            else /* unknown specifier -> print as is */
            {
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else /* normal char */
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
