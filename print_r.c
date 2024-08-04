#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_r - Prints a literal "%r" string.
 * @args: List of arguments (unused in this function).
 *
 * Return: Number of characters printed.
 */
int print_r(va_list args)
{
(void)args; /* Unused parameter */
return (write(1, "%r", 2));
}
