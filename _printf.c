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
		if (format[i] == '%' && format[i + 1] != '\0') 
		{
			if (format[i + 1] == 'c') 
			{
				print_char(args, &countCharacters);
				i++;
	     			continue;  
	  		} 
			if (format[i + 1] == 's') 
			{				
		  		print_string(args, &countCharacters);
				i++;
				continue;			
			} 
			if (format[i + 1] == 'd' || format[i + 1] == 'i') 
			{		    
				print_integer(args, &countCharacters);
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
			write(1, &format[i], 1);
			countCharacters++;
		}
	
	}
	return (countCharacters);
}
