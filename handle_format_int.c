#include "main.h"

/**
* handle_format_int - Handles the 'd' and 'i' format specifiers.
* @args: Argument list containing the integer to print.
*
* Return: Number of characters printed.
*/
int handle_format_int(va_list args)
{
return (print_int(args));
}

