#include "main.h"
#include <stdarg.h>
#include <unistd.h>

static int handle_format(char format, va_list args);

/**
 * _printf - Custom implementation of printf function.
 * @format: Format string containing the characters and format specifiers.
 * @...: Additional arguments based on format specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
count += handle_format(*format, args);
}
else
{
write(1, format, 1);
count++;
}
format++;
}

va_end(args);
return (count);
}

/**
 * handle_format - Handles format specifiers using function pointers.
 * @format: The current format specifier.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
static int handle_format(char format, va_list args)
{
int count = 0;

switch (format)
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case '%':
count += print_percent(args);
break;
case 'd':
case 'i':
count += print_int(args);
break;
default:
write(1, &format, 1);
count++;
break;
}

return (count);
}

