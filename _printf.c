#include "main.h"
#include <stdarg.h>
#include <unistd.h>

static int handle_format(char format, va_list args);
static int print_default(char format);

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
 * handle_format - Handles format specifiers.
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
case 'b':
count += print_binary(args);
break;
case 'o':
count += print_octal(args);
break;
case 'x':
count += print_hex(args);
break;
case 'X':
count += print_hexUpper(args);
break;
case 'u':
count += print_unsignedint(args);
break;
case 'S':
count += print_special_string(args);
break;
case 'a':
count += print_stringAscii(args);
break;
case 'r':
count += print_r(args);
break;
case 'p':
count += print_p(args);
break;
default:
count += print_default(format);
break;
}

return (count);
}

/**
 * print_default - Handles default case for format specifiers.
 * @format: The format specifier that is not handled.
 *
 * Return: Number of characters printed (1 in this case).
 */
static int print_default(char format)
{
return (write(1, &format, 1));
}

