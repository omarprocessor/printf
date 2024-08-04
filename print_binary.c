#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_number_binary - Prints an unsigned integer in binary format.
 * @n: The number to be converted to binary and printed.
 *
 * Return: Number of characters printed.
 */
int print_number_binary(unsigned int n)
{
char buffer[32];
int i = 0;
int len = 0;

if (n == 0)
return (write(1, "0", 1));

while (n > 0)
{
buffer[i++] = (n % 2) ? '1' : '0';
n /= 2;
}

while (i > 0)
len += write(1, &buffer[--i], 1);

return (len);
}

/**
 * print_binary - Handles the 'b' conversion specifier to print
 * an unsigned integer in binary format.
 * @args: va_list containing the unsigned integer to print.
 *
 * Return: Number of characters printed.
 */
int print_binary(va_list args)
{
return (print_number_binary(va_arg(args, unsigned int)));
}

