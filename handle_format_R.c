#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * handle_format_R - Handles the 'R' format specifier for ROT13-encoded string.
 * @args: Argument list containing the string to print.
 *
 * Return: Number of characters printed.
 */
int handle_format_R(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;
char c;

while (*str)
{
c = *str;
if ((c >= 'a' && c <= 'z'))
{
c = ((c - 'a' + 13) % 26) + 'a';
}
else if ((c >= 'A' && c <= 'Z'))
{
c = ((c - 'A' + 13) % 26) + 'A';
}
write(1, &c, 1);
str++;
len++;
}

return (len);
}
