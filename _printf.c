#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - function that produces output according to a format.
 * @format: Is a pointer strings.
 *
 * Return: a count characters.
*/
int _printf(const char *format, ...)
{
	int formatCopy;
	int countCharacters = 0;
	va_list args;

	va_start(args, format);

	for (formatCopy = 0; format[formatCopy] != '\0'; formatCopy++)
	{
		if (format[formatCopy] == '%' && format[formatCopy] != '%')
		{
			if (format[formatCopy] == 'c' || format[formatCopy] == 's')
			{
				char *string = (format[formatCopy] == 'c')
					? 
				(char[])(va_arg(args, int), '\0') : va_arg(args, char *);
				while (*string)
					write(1, string++, 1);
				countCharacters += (format[formatCopy] == 'c' || *string) ? 1 : 0;
			}
			else if (format[formatCopy] == '%')
			{
				write(1, '%', 1);
				countCharacters++;
			}
		}
		else
		{
			write(1, &format[formatCopy], 1);
			countCharacters++;
		}
	}
	va_end(args);
	return (countCharacters);
}
