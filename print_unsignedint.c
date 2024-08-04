#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_number_unsignedint - Prints an unsigned integer.
 * @n: The unsigned integer to print.
 *
 * Return: Number of characters printed.
 */
int print_number_unsignedint(unsigned int n)
{
char buffer[10];
int i = 0;
int len = 0;

if (n == 0)
{
return (write(1, "0", 1));
}

while (n > 0)
{
buffer[i++] = '0' + (n % 10);
n /= 10;
}

while (i > 0)
{
len += write(1, &buffer[--i], 1);
}

return (len);
}

/**
 * print_unsignedint - Prints an unsigned integer from va_list.
 * @args: List of arguments containing the unsigned integer.
 *
 * Return: Number of characters printed.
 */
int print_unsignedint(va_list args)
{
return (print_number_unsignedint(va_arg(args, unsigned int)));
}
