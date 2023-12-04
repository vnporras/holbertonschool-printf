#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct convert - associate symbols with functions
 * @symbol: pointer to a character that contains a symbol or a string
 * @function: pointer to a function that takes an argument of type 
 * va_list and returns an integer
 */

struct convert
{
	char *symbol;
	int (*function)(va_list);
};
typedef struct convert convert_t;

/**
 * prototypes:
 */

int _printf(const char *format, ...);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int unsigned_integer(va_list);
int print_unsgned_number(unsigned int);
int print_reversed(va_list);
int recording_error(const char *format, convert_t f_list[], va_list arg_list);

#endif
