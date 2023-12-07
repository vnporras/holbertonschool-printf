#include "main.h"

/**
 * print_char - function that prints a char or a percent
 * @args: va_list that contains aguments of the function
 * @countCharacters: pointer to a int that counts characters
 *
 * Return: void
 */

void print_char_or_percent(const char *format, int *countCharacters, va_list args) 
{
	if (format[1] == 'c')
	{
		char c = va_arg(args, int);
		write(1, &c, 1);
		(*countCharacters)++;
		continue;
	}
	if (format[1] == '%')
	{
		write(1, &format[1], 1);
		(*countCharacters)++;
		continue;
	}
}
