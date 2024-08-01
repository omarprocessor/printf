#include "main.h"

/**
* handle_format_r - Handles the 'r' format specifier.
* @args: Argument list containing the string to print in reverse.
*
* Return: Number of characters printed.
*/
int handle_format_r(va_list args)
{
return (print_r(args));
}

