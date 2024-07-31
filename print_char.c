#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - Prints a single character.
 * @args: List of arguments containing the character to print.
 *
 * Return: Number of characters printed (1 in this case).
 */
int print_char(va_list args)
{
char c = va_arg(args, int);

return (write(1, &c, 1));
}
