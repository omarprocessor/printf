#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
