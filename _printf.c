#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
* _printf - Custom implementation of printf that handles various format
*           specifiers and prints the corresponding arguments.
* @format: Format string that specifies how to format the output.
* @...: Variadic arguments to be formatted and printed.
*
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
++;
count += handle_format(format[i], args);
}
else
{
_putchar(format[i]);
count++;
}
++;
}

va_end(args);
return (count);
}

/**
 * handle_specifier - Handles a format specifier
 * @specifier: The format specifier character
 * @args: The argument list
 *
 * Return: The number of characters printed
 */

int handle_specifier(char specifier, va_list args)

{
int count = 0;

switch (specifier)
{
case 'c':
count = print_char(va_arg(args, int));
break;
case 's':
count = print_string(va_arg(args, char *));
break;
case 'p':
count = print_pointer(va_arg(args, void *));
break;
case '%':
_putchar('%');
count = 1;
break;
default:
_putchar('%');
_putchar(specifier);
count = 2;
break;
}
return (count);
}
