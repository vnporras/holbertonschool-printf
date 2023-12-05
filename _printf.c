#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: character string
 *
 * Return - int, chars
 */

int _printf(const char *format, ...)
{
	/**
	 * var that will count and store the number of characters printed
	 */
	int chars;

	convert_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"u", unsigned_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{NULL, NULL}
	};

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	chars = recording_error(format, f_list, arg_list);
	va_end(arg_list);
	return (chars);
}
