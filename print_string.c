#include "main.h"

/**
 * print_string - function that prints a string
 * @args: va_list arguments
 * @countCharacters: pointer to a count of characters
 *
 * Return: void
 */

void print_string(char *s, int *countCharacters) 
{
	if (s == NULL) 
	{
		write(1, "(null)", 6);
		(*countCharacters) += 6;
		return;
	}

	while (*s != '\0')
	{
		write(1, s++, 1);
		(*countCharacters)++;
	}
}
