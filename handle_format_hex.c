#include "main.h"

/**
* handle_format_hex - Handles the 'x' format specifier.
* @args: Argument list containing the integer to print in hexadecimal.
*
* Return: Number of characters printed.
*/
int handle_format_hex(va_list args)
{
return (print_hex(args));
}

