#include <unistd.h>

/**
 * print_int - prints a signed integer
 * @n: number to print
 * Return: number of characters printed
 */
int print_int(int n)
{
    char buf[12];
    int i = 0, count = 0;
    long x = n;

    if (x < 0)
    {
        count += write(1, "-", 1);
        x = -x;
    }

    if (x == 0)
    {
        count += write(1, "0", 1);
        return (count);
    }

    while (x > 0)
    {
        buf[i++] = (x % 10) + '0';
        x /= 10;
    }

    while (i--)
        count += write(1, &buf[i], 1);

    return (count)
}
