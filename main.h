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
void print_char_or_percent(char c, int *countCharacters);
void print_string(char *s, int *countCharacters);
void print_integer(int number, int *countCharacters);

#endif
