#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @index: List of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *index, va_list args)
{
	int i = *index + 1;
	int precision = -1;

	if (format[i] != '.')
	{
		return (precision);
	}

	precision = 0;

	for (i += 1; format[i] != '\0'; i++)
	{
		if (is_digit(format[i]))
		{
			precision *= 10;
			precision += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = i - 1;

	return (precision);
}
