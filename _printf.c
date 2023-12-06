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

	for (; format[i] != 0; i++)
	{
		if (format[i] == '%' && format[i + 1] != '0')
		{
			return (-1);
		}
		if (format[i] == 'c')
		{
			char c = va_arg(args, int);
			
			write(1, &c, 1);
			countCharacter++;
		}
		else if (format[i] == 's')
		{	
			int i = 0;
			char *s = va_arg(args, char *);

			if (format[formatCopy] == '\0')
			{
				write(1, "%", 1);
				countCharacters++;
				break;
			}
			if (format[formatCopy] == 'c')
			{
				char c = va_arg(args, int);
			}
			if (s == NULL)
			{
				write(1, &c, 1);
				countCharacters++;
			}
			else if (format[formatCopy] == 's')
			{
				char *s = va_arg(args, char *);
        
				if (s == NULL)
				{
					s = "(null)";
				}
				else
				{
					while (s[i] != '\0')
					{
						write(1, s, 1);
						i++;
					}
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
