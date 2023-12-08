#include "main.h"

void print_integer(va_list args, int *countCharacters)
{
	int number = va_arg(args, int);
	int count = 0;
	char number_character;
	int power = 1;
	int temp = number;
	int digit = number / power;

	if (number == 0)
	{
		write(1, "0", 1);
		count++;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		count++;
		number = -number;
	}
	while (temp / 10 != 0)
	{
		temp /= 10;
		power *= 10;
	}
	while (power > 0)
	{
		number_character = '0' + digit;
		write(1, &number_character, 1);
		(*countCharacters)++;
		number %= power;
		power /= 10;
		count++;
	}
}
