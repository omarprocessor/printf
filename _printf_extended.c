#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_number - Prints an integer as a string
 * @n: The integer to print
 * Return: The number of characters printed
 */
int print_number(int n)
{
char buffer[10];
int i = 0, count = 0, sign = 0;

if (n < 0)
{
sign = 1;
n = -n;
}

do {
buffer[i++] = (n % 10) + '0';
n /= 10;
} while (n > 0);

if (sign)
{
_putchar('-');
count++;
}

while (i > 0)
{
_putchar(buffer[--i]);
count++;
}

return (count);
}

/**
 * _printf - Custom printf function with extended specifiers
 * @format: The format string
 * @...: The values to format
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;

va_start(args, format);

for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr == '%' && (*(ptr + 1) == 'd' || *(ptr + 1) == 'i'))
{
ptr++;
count += print_number(va_arg(args, int));
}
else
{
_putchar(*ptr);
count++;
}
}

va_end(args);
return (count);
}
