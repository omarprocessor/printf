#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int print_char(va_list c);
int print_string(va_list *str);
int print_percent(va_list args);
int print_int(va_list args);
int print_number(int n);
int print_binary(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hexUpper(va_list args);
int print_unsignedint(va_list args);
int print_special_string(va_list args);
int print_stringAscii(va_list args);
int print_r(va_list args);
int print_p(va_list args);
int print_number_unsignedint(unsigned int n);
int _printf(const char *format, ...);
int handle_format(char format, va_list args);
int handle_format_char(va_list args);
int handle_format_string(va_list args);
int handle_format_percent(va_list args);
int handle_format_int(va_list args);
int handle_format_binary(va_list args);
int handle_format_octal(va_list args);
int handle_format_hex(va_list args);
int handle_format_hexUpper(va_list args);
int handle_format_unsignedint(va_list args);
int handle_format_special_string(va_list args);
int handle_format_stringAscii(va_list args);
int handle_format_r(va_list args);
int handle_format_p(va_list args);
int _putchar(char c);
int print_percent(va_list args);
/*int print_number_hex(unsigned int num);*/
int print_number_hex(unsigned int n);
#endif

