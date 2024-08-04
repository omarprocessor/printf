#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_string - Prints a string.
 * @args: List of arguments containing the string to print.
 *
 * Return: Number of characters printed.
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;

if (str == NULL)
str = "(null)"; /* Handle NULL string */

while (*str)
{
len += write(1, str++, 1);
}

return (len);
}
