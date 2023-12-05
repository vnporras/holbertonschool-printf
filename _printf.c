#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
   
/**
 * _printf - function that produces output according to a format.
 * @format: Is a pointer strings.
 *
 * Return - a count characters
*/
int _printf(const char *format, ...)
{
	int formatCopy = 0;
	int countCharacters = 0;
	int sCopy = 0;
	va_list args; 
	va_start(args, format);
	while (format[formatCopy] != '\0')
	{
		if (format[formatCopy] == '%') 
		{
			formatCopy++;
			if (format[formatCopy] == 'c')
			{
				char c = va_arg(args, int); 
				write(1, &c, 1);
				countCharacters++;
			}
			else if (format[formatCopy] == 's')
			{
				char *s = va_arg(args, char *);

				if (s == NULL)
				{
					write(1, "(null)", 6);
					countCharacters += 6;
				}
				else
				{
					int sCopy = 0;

					while (s[sCopy] != '\0')
					{
						write(1, &s[sCopy], 1);
						sCopy++;
						countCharacters++;
					}
				}

				while (s[sCopy] != '\0')
				{
					write(1, &s[sCopy], 1);
					sCopy++;
					countCharacters++;
				}
			}
			else if (format[formatCopy] == '%')
			{
				write(1, &format[formatCopy], 1);
				countCharacters++;
			}
		}
		else
		{
			write(1, &format[formatCopy], 1); 
			countCharacters++;
		}
		formatCopy++;
	}
	va_end(args);
	return (countCharacters);
}
