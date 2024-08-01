#include "main.h"

/**
* handle_format_string - Handles the 's' format specifier.
* @args: Argument list containing the string to print.
*
* Return: Number of characters printed.
*/
int handle_format_string(va_list args)
{
return (print_string(args));
}

