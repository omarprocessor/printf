#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_stringAscii - Prints a string with non-printable characters
 * replaced by their hexadecimal code.
 * @args: va_list containing the string to print.
 *
 * Return: Number of characters printed.
 */
int print_stringAscii(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;
char hex[4];
char digits[] = "0123456789ABCDEF";

while (*str)
{
if (*str < 32 || *str >= 127) /* Non-printable characters */
{
hex[0] = '\\';
hex[1] = 'x';
hex[2] = digits[(*str / 16) % 16];
hex[3] = digits[*str % 16];
len += write(1, hex, 4); /* Print the escaped character */
}
else
{
len += write(1, str, 1); /* Print printable characters */
}
str++;
}
return (len);
}

