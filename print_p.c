#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_p - Prints a pointer address in hexadecimal format.
 * @args: List of arguments containing the pointer to print.
 *
 * Return: Number of characters printed.
 */
int print_p(va_list args)
{
unsigned long addr = (unsigned long)va_arg(args, void *);
int len = 0;

len += write(1, "0x", 2); /* Print the '0x' prefix */
len += print_number_hex(addr); /* Print the address in hexadecimal */

return (len);
}

