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

	for (; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				print_char_or_percent(&format[i], &countCharacters, args);
				print_string(&format[i], &countCharacters, args);
				print_integer(&format[i], &countCharacters, args);
				i++;
				continue;
			}
		}
		write(1, &format[i], 1);
		countCharacters++;
	}
	va_end(args);
	return countCharacters;
}
