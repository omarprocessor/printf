#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_number_octal - Prints an unsigned integer in octal format.
 * @n: The unsigned integer to print.
 *
 * Return: Number of characters printed.
 */
int print_number_octal(unsigned int n)
{
char buffer[32];
int i = 0;
int len = 0;

if (n == 0)
{
return (write(1, "0", 1));
}

while (n > 0)
{
buffer[i++] = '0' + (n % 8);
n /= 8;
}

while (i > 0)
{
len += write(1, &buffer[--i], 1);
}

return (len);
}

/**
 * print_octal - Prints an unsigned integer in octal format from va_list.
 * @args: List of arguments containing the unsigned integer.
 *
 * Return: Number of characters printed.
 */
int print_octal(va_list args)
{
return (print_number_octal(va_arg(args, unsigned int)));
}
