#include "main.h"

/**
 * print_string - function that prints a string
 * @args: va_list arguments
 * @countCharacters: pointer to a count of characters
 *
 * Return: void
 */

void print_string(va_list args, int *countCharacters) 
{
	char *s = va_arg(args, char *);
	int sCopy = 0;

	if (s == NULL) 
	{
		write(1, "(null)", 6);
		(*countCharacters) += 6;
		return;

		for (; s[sCopy] != '\0'; sCopy++)
		{
		write(1, &s[sCopy], 1);
		(*countCharacters)++;
		}
	}
}
