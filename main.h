#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int print_char(va_list args);
int print_string(va_list args);
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

int _printf(const char *format, ...);

#endif 

