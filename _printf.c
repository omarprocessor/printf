#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - Writes a single character to standard output.
 * @c: The character to be written.
 * @count: Pointer to the count of printed characters.
 */
void print_char(char c, int *count)
{
write(1, &c, 1);
(*count)++;
}

/**
 * print_string - Writes a string to standard output.
 * @s: The string to be written.
 * @count: Pointer to the count of printed characters.
 * If the string is NULL, "(null)" is printed.
 */
void print_string(char *s, int *count)
{
if (s == NULL)
s = "(null)";
while (*s)
{
write(1, s, 1);
s++;
(*count)++;
}
}

/**
 * handle_format - Handles format specifiers in the format string.
 * @specifier: The format specifier to handle.
 * @args: The list of arguments.
 * @count: Pointer to the count of printed characters.
 */
void handle_format(char specifier, va_list args, int *count)
{
char c;
char *s;
if (specifier == 'c')
{
c = va_arg(args, int);
print_char(c, count);
}
else if (specifier == 's')
{
s = va_arg(args, char *);
print_string(s, count);
}
else if (specifier == '%')
{
print_char('%', count);
}
else
{
print_char('%', count);
print_char(specifier, count);
}
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: The values to format and print.
 * Return: The number of characters printed, or -1 on failure.
 */
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
if (format == NULL)
return (-1);
va_start(args, format);
while (format[i])
{
if (format[i] == '%')
{
i++;
handle_format(format[i], args, &count);
}
else
{
print_char(format[i], &count);
}
i++;
}
va_end(args);
return (count);
}
