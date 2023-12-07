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
	char number_character;

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
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
					i++;
					continue;
				}
			
				for (; s[sCopy] != '\0'; sCopy++)
				{
					write(1, &s[sCopy], 1);
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
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int number = va_arg(args, int);
				int count = 0;
				int sign = 1;
				int number_digit, last_digit = 0;
				unsigned int power;

				if (number == 0)
				{
					write(1, "0", 1);
				}

				if (number < 0)
				{
					write(1, "-", 1);
					sign = -1;
					count++;
				}

				number = number * sign;
				power = 1;

				while (number / power)
				{
					power = power * 10;
				}

				power = power / 10;

				while (power != 0)
				{
					number_digit = (number / power);
					last_digit = (number_digit % 10);
					number_character = '0' + last_digit;
					write (1, &number_character, 1);
					count++;
					power = power / 10;
				}

				countCharacters += count;
				i++;
				continue;
			}
			write(1, &format[i], 1);
			countCharacters++;
			continue;
		}
		write(1, &format[i], 1);
		countCharacters++;
	}
	va_end(args);
	return (countCharacters);
}
