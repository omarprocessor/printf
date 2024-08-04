#include "main.h"

/**
 * handle_format - Dispatches the format
 * specifier to the corresponding handler.
 * @specifier: Format specifier character.
 * @args: Argument list to pass to the format handler.
 *
 * Return: Number of characters printed.
 */
int handle_format(const char specifier, va_list args)
{
switch (specifier)
{
case 'c':
return (handle_format_char(args));
case 's':
return (handle_format_string(args));
case '%':
return (handle_format_percent(args));
case 'd':
case 'i':
return (handle_format_int(args));
case 'b':
return (handle_format_binary(args));
case 'o':
return (handle_format_octal(args));
case 'x':
return (handle_format_hex(args));
case 'X':
return (handle_format_hexUpper(args));
case 'u':
return (handle_format_unsignedint(args));
case 'S':
return (handle_format_special_string(args));
case 'a':
return (handle_format_stringAscii(args));
case 'r':
return (handle_format_r(args));
case 'p':
return (handle_format_p(args));
case 'R':
return (handle_format_R(args));
default:
write(1, &specifier, 1);
return (1);
}
}

