#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
/*int print_binary(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hexUpper(va_list args);
int print_unsignedint(va_list args);
int print_special_string(va_list args);
int print_stringAscii(va_list args);
int print_r(va_list args);
int print_p(va_list args);
*/
typedef int (*print_func)(va_list);

/**
 * handle_format - Handles format specifiers using function pointers.
 * @format: The current format specifier.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
int handle_format(char format, va_list args)
{
static print_func func_arr[] = {
['c' - 'c'] = print_char,
['s' - 'c'] = print_string,
['%' - 'c'] = print_percent,
['d' - 'c'] = print_int,
['i' - 'c'] = print_int,
/*['b' - 'c'] = print_binary,
['o' - 'c'] = print_octal,
['x' - 'c'] = print_hex,
['X' - 'c'] = print_hexUpper,
['u' - 'c'] = print_unsignedint,
['S' - 'c'] = print_special_string,
['a' - 'c'] = print_stringAscii,
['r' - 'c'] = print_r,
['p' - 'c'] = print_p
*/
};
int count = 0;
int index = format - 'c';
int len = (sizeof(func_arr) / sizeof(func_arr[0]);

if (index >= 0 && index < len && func_arr[index])
{
count += func_arr[index](args);
}
else
{
write(1, &format, 1);
count++;
}

return (count);
}

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

