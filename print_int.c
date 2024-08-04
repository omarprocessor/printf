#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_number - Converts an integer to a string and prints it.
 * @n: The integer to print.
 *
 * Return: Number of characters printed.
 */
int print_number(int n)
{
char buffer[10];
int i = 0;
int len = 0;
int negative = 0;

if (n < 0)
{
negative = 1;
n = -n;
}

do {
buffer[i++] = '0' + (n % 10);
n /= 10; }

while (n > 0);

if (negative)
{
buffer[i++] = '-';
}

while (i > 0)
{
len += write(1, &buffer[--i], 1);
}

return (len);
}

/**
 * print_int - Extracts the integer from the argument list and prints it.
 * @args: List of arguments containing the integer to print.
 *
 * Return: Number of characters printed.
 */
int print_int(va_list args)
{
return (print_number(va_arg(args, int)));
}

