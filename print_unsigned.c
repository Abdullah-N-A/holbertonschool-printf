#include <unistd.h>

/**
 * print_unsigned - prints an unsigned int in decimal
 * @n: number to print
 * Return: number of characters printed
 */
int print_unsigned(unsigned int n)
{
    char buf[32];
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n > 0)
    {
        buf[i++] = (n % 10) + '0';
        n /= 10;
    }

    while (i--)
        count += write(1, &buf[i], 1);

    return count;
}

/**
 * print_octal - prints an unsigned int in octal
 * @n: number to print
 * Return: number of characters printed
 */
int print_octal(unsigned int n)
{
    char buf[32];
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n > 0)
    {
        buf[i++] = (n % 8) + '0';
        n /= 8;
    }

    while (i--)
        count += write(1, &buf[i], 1);

    return count;
}

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @n: number to print
 * @uppercase: 1 for uppercase, 0 for lowercase
 * Return: number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
    char buf[32];
    int i = 0, count = 0;
    char base_char = uppercase ? 'A' : 'a';

    if (n == 0)
        return write(1, "0", 1);

    while (n > 0)
    {
        int digit = n % 16;
        if (digit < 10)
            buf[i++] = digit + '0';
        else
            buf[i++] = (digit - 10) + base_char;
        n /= 16;
    }

    while (i--)
        count += write(1, &buf[i], 1);

    return count;
}
