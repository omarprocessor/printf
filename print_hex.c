#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_number_hex - Prints an unsigned long integer in hexadecimal format.
 * @n: The unsigned long integer to print.
 *
 * Return: Number of characters printed.
 */
int print_number_hex(unsigned long n)
{
char hex_digits[] = "0123456789abcdef";
char buffer[16];
int len = 0;
int i;

if (n == 0)
{
buffer[len++] = '0';
}
else
{
while (n > 0)
{
buffer[len++] = hex_digits[n % 16];
n /= 16;
}
}

for (i = len - 1; i >= 0; i--)
{
write(1, &buffer[i], 1);
}

return (len);
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format from va_list.
 * @args: List of arguments containing the unsigned integer.
 *
 * Return: Number of characters printed.
 */
int print_hex(va_list args)
{
return (print_number_hex(va_arg(args, unsigned int)));
}
