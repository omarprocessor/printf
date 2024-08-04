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
 * _printf - Custom printf function
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
if (*ptr == '%' && (*(ptr + 1) == 'c' || *(ptr + 1) == 's' || *(ptr + 1) == '%'))
{
ptr++;
if (*ptr == 'c')
{
_putchar(va_arg(args, int));
count++;
}
else if (*ptr == 's')
{
char *str = va_arg(args, char *);
while (*str)
{
_putchar(*str++);
count++;
}
}
else if (*ptr == '%')
{
_putchar('%');
count++;
}
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
