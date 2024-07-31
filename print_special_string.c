#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_special_string - Prints a string with non-printable characters
 *                        replaced by \x followed by their ASCII code.
 * @args: List of arguments containing the string to print.
 *
 * Return: Number of characters printed.
 */
int print_special_string(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;
char hex[3];

while (*str)
{
if (*str < 32 || *str >= 127)
{
hex[0] = '\\';
hex[1] = 'x';
hex[2] = '\0';

len += write(1, hex, 2);
len += write(1, "0123456789ABCDEF" + ((*str / 16) % 16), 1);
len += write(1, "0123456789ABCDEF" + (*str % 16), 1);
}
else
{
len += write(1, str, 1);
}
str++;
}

return (len);
}
