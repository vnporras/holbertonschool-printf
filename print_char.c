#include "main.h"

/**
 * print_char - function that prints a char
 * @args: va_list that contains aguments of the function
 * @countCharacters: pointer to a int that counts characters
 *
 * Return: void
 */

void print_char(va_list args, int *countCharacters) 
{
	char c = va_arg(args, int);
        write(1, &c, 1);
	(*countCharacters)++;
}
