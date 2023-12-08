#include "main.h"

void print_integer(int number, int *countCharacters)
{
	char buffer[20];
	int buffer_counter = 0;
	int i;

	if (number == 0)
	{
		write(1, "0", 1);
		(*countCharacters)++;
		return;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		(*countCharacters)++;
		number = -number;
	}
	while (number != 0)
	{
		buffer[buffer_counter++] = '0' + (number % 10);
		number /= 10;
	}
	for (i = buffer_counter - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
		(*countCharacters)++;
	}
}
