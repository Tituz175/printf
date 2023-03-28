#include "main.h"

/**
 * get_width -> this function handle the given width
 * @format: pointer to the given string
 * @index: pointer to the index of the given string
 * @args: list of args
 * Return: the width
 */

int get_width(const char *format, int *index, va_list args)
{
	int width = 0, i;

	for (i = *index + 1; format[i] != '\0'; i++)
	{
		if (is_digit(format[i]))
		{
			width *= 10;
			width += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*index = i - 1;

	return (width);
}
