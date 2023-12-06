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
<<<<<<< HEAD
=======
	int sCopy = 0;
  
>>>>>>> 225985c57303bc360ab7a776f343429559fcfee8
	va_list args;

	va_start(args, format);

	for (; format[i] != 0; i++)
	{
		if (format[i] == '%' && format[i + 1] != '0')
			return (-1);

		if (format[i] == 'c')
		{
			char c = va_arg(args, int);

<<<<<<< HEAD
			write(1, &c, 1);
			countCharacter++;
		}
		else if (format[i] == 's')
		{	
			int i = 0;
			char *s = va_arg(args, char *);

			if (s == NULL)
=======
				write(1, &c, 1);
				countCharacters++;
			}
			else if (format[formatCopy] == 's')
			{
				char *s = va_arg(args, char *);
        
				if (s == NULL)
>>>>>>> 225985c57303bc360ab7a776f343429559fcfee8
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
