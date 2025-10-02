#include <unistd.h>

/**
 * print_binary - prints an unsigned int in binary
 * @n: number to print
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
    char buf[32];
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n > 0)
    {
        buf[i++] = (n & 1) + '0';
        n >>= 1;
    }

    while (i--)
        count += write(1, &buf[i], 1);

    return count;
}
