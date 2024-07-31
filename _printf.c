#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
switch (*format)
{
case 'c': count += print_char(args); break;
case 's': count += print_string(args); break;
case '%': count += print_percent(args); break;
case 'd': case 'i': count += print_int(args); break;
case 'b': count += print_binary(args); break;
case 'o': count += print_octal(args); break;
case 'x': count += print_hex(args); break;
case 'X': count += print_hexUpper(args); break;
case 'u': count += print_unsigned(args); break;
case 'S': count += print_special_string(args); break;
case 'a': count += print_stringAscii(args); break;
case 'r': count += print_r(args); break;
case 'p': count += print_p(args); break;
default: write(1, format, 1); count++; break;
}
}
else
{
write(1, format, 1);
count++;
}
format++;
}

va_end(args);
return(count);
}

