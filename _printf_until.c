#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/* Prototype for helper function to print integers */
int print_number(int n);

/**
 * _printf - A custom printf function that handles %d and %i.
 * @format: The format string.
 * @...: The variables to format.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *p;

va_start(args, format);

for (p = format; *p; p++)
{
if (*p == '%' && (*(p + 1) == 'd' || *(p + 1) == 'i'))
{
int num = va_arg(args, int);
count += print_number(num);
p++;
}
else
{
write(1, p, 1);
count++;
}
}

va_end(args);
return (count);
}

/**
 * print_number - Prints an integer to stdout.
 * @n: The integer to print.
 * Return: The number of characters printed.
 */
int print_number(int n)
{
int count = 0;
char buffer[12]; /* Buffer to hold the integer string */
char *ptr = buffer + sizeof(buffer) - 1;

*ptr = '\0'; /* Null-terminate the buffer */

if (n == 0)
{
write(1, "0", 1);
return (1);
}

if (n < 0)
{
write(1, "-", 1);
n = -n;
count++;
}

while (n > 0)
{
*--ptr = (n % 10) + '0';
n /= 10;
}

write(1, ptr, buffer + sizeof(buffer) - ptr);
count += buffer + sizeof(buffer) - ptr;

return (count);
}
