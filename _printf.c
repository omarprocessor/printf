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

