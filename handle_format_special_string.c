#include "main.h"

/**
* handle_format_special_string - Handles the 'S' format specifier.
* @args: Argument list containing the string with special characters to print.
*
* Return: Number of characters printed.
*/
int handle_format_special_string(va_list args)
{
return (print_special_string(args));
}

