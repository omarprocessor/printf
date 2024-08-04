#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_number_hex - Prints an unsigned long integer in hexadecimal format.
 * @n: The unsigned long integer to print.
 *
 * Return: Number of characters printed.
 */

int print_number_hex(unsigned long num)
{
char hex_digits[] = "0123456789abcdef";
int count = 0;
if (num == 0)
{
_putchar('0');
return 1;
}
if (num >= 16)
{
count += print_number_hex(num / 16);
}
_putchar(hex_digits[num % 16]);
count++;
return (count);
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format from va_list.
 * @args: List of arguments containing the unsigned integer.
 *
 * Return: Number of characters printed.
 */
int print_hex(va_list args)
{
return (print_number_hex(va_arg(args, unsigned long)));
}
