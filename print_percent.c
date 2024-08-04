#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_percent - Prints a percent sign.
 * @args: List of arguments (unused).
 *
 * Return: Number of characters printed (1 in this case).
 */
int print_percent(va_list args)
{
(void)args;  /* Unused parameter */

return (write(1, "%", 1));
}
