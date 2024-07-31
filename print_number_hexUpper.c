#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_number_hexUpper - Prints an unsigned integer
 * in uppercase hexadecimal format.
 * @n: The number to be converted to uppercase hexadecimal and printed.
 *
 * Return: Number of characters printed.
 */
int print_number_hexUpper(unsigned int n)
{
char buffer[32];
char hex[] = "0123456789ABCDEF";
int i = 0;
int len = 0;

if (n == 0)
return (write(1, "0", 1));

while (n > 0)
{
buffer[i++] = hex[n % 16];
n /= 16;
}

while (i > 0)
len += write(1, &buffer[--i], 1);

return (len);
}

/**
 * print_hexUpper - Handles the 'X' conversion specifier to print
 * an unsigned integer in uppercase hexadecimal format.
 * @args: va_list containing the unsigned integer to print.
 *
 * Return: Number of characters printed.
 */
int print_hexUpper(va_list args)
{
return (print_number_hexUpper(va_arg(args, unsigned int)));
}

