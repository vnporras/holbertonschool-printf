#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: Is a pointer strings.
 *
 * Return: a count characters.
 */

int _printf(const char *format, ...) 
{
	int i = 0;
	int countCharacters = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 'c')
				print_char_or_percent(va_arg(args, int), &countCharacters);
			if (format[i] == 's')
				print_string(va_arg(args, char *), &countCharacters);
			if (format[i] == 'd' || format[i] == 'i')
				print_integer(va_arg(args, int), &countCharacters);
			if (format[i] == '%')
				print_char_or_percent('%', &countCharacters);
		}
		else 
		{
			write(1, &format[i], 1);
			countCharacters++;
		}
		i++;
	}
	va_end(args);
	return countCharacters;
}
