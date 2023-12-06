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

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				countCharacters++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				int sCopy = 0;

				while (s[sCopy] != '\0')
				{
					write(1, &s[sCopy], 1);
					sCopy++;
					countCharacters++;
				}
			}
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				countCharacters++;
			}
			else if (format[i] == 'd')
			{
				int d = va_arg(args, int);
				write(1, &d, 1);
				countCharacters++;
			}
			else if (format[i] == 'i')
			{
				int i = va_arg(args, int);
				write(1, &i, 1);
				countCharacters++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			countCharacters++;
		}
		i++;
	}
	va_end(args);
	return (countCharacters);
}
