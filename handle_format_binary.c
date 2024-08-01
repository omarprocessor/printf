#include "main.h"

/**
* handle_format_binary - Handles the 'b' format specifier.
* @args: Argument list containing the integer to print in binary.
*
* Return: Number of characters printed.
*/
int handle_format_binary(va_list args)
{
return (print_binary(args));
}

