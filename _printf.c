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
	int sCopy = 0;
	va_list args;

	va_start(args, format);

	for (;format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (format[i + 1] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				countCharacters++;
				i++;
				continue;
			}
			if (format[i + 1] == 's')
			{
				char *s = va_arg(args, char *);
				sCopy = 0;

				if (s == NULL)
				{					
					write(1, "(null)", 6);
					countCharacters += 6;
					continue;
				}
			
				while (s[sCopy] != '\0')
				{
					write(1, &s[sCopy], 1);
					sCopy++;
					countCharacters++;
				}
				i++;
				continue;
			}
			if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				countCharacters++;
				i++;
				continue;
			}
			if (format[i + 1] == 'd')
			{
				int d = va_arg(args, int);
				write(1, &d, 1);
				countCharacters++;
				i++;
				continue;
			}
			if (format[i + 1] == 'i')
			{
				int number = va_arg(args, int);
				write(1, &number, 1);
				countCharacters++;
				i++;
				continue;
		
			}
			write(1, &format[i + 1], 1);
			countCharacters++;
			continue;
		}
		write(1, &format[i + 1], 1);
		countCharacters++;
	}
	va_end(args);
	return (countCharacters);
}
