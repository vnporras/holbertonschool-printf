#include "main.h"

/**
 * print_char - function that prints a char or a percent
 * @args: va_list that contains aguments of the function
 * @countCharacters: pointer to a int that counts characters
 *
 * Return: void
 */

void print_char_or_percent(char c, int *countCharacters)
{
	write(1, &c, 1);
	(*countCharacters)++;
}
