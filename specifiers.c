#include "main.h"
#include <unistd.h>

/**
 * print_char - Prints a character
 * @c: The character to print
 *
 * Return: The number of characters printed
 */
int print_char(char c)
{
return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
int i = 0;

if (!str)
str = "(null)";
while (str[i])
{
_putchar(str[i]);
i++;
}
return (i);
}

/**
 * print_pointer - Prints a pointer address
 * @ptr: The pointer to print
 *
 * Return: The number of characters printed
 */
int print_pointer(void *ptr)
{
unsigned long address = (unsigned long)ptr;
char buffer[20];
char *hex = "0123456789abcdef";
int i = 18, count = 0;

buffer[19] = '\0';
if (!ptr)
{
return (print_string("(nil)"));
}

while (address)
{
buffer[i--] = hex[address % 16];
address /= 16;
}
buffer[i--] = 'x';
buffer[i] = '0';

return (print_string(&buffer[i]));
}
