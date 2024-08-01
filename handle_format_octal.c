#include "main.h"

/**
* handle_format_octal - Handles the 'o' format specifier.
* @args: Argument list containing the integer to print in octal.
*
* Return: Number of characters printed.
*/
int handle_format_octal(va_list args)
{
return (print_octal(args));
}

