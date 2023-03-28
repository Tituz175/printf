#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @format: formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @symbol: the function symbol.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *format, int *symbol, va_list args,
char buffer[], int flags, int width, int precision, int size)
{
	int lenUnknow = 0, index = 0, count = -1;

	function functionsArray[] = {
		{'c', print_char}, {'s', print_string},	{'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
		};

	for (index = 0; functionsArray[index].functionSymbol != '\0'; index++)
	{
		if (format[*symbol] == functionsArray[index].functionSymbol)
		{
			count = functionsArray[index].function(args, buffer, flags,
								width, precision, size);
			return (count);
		}
	}
	if (functionsArray[index].functionSymbol == '\0')
	{
		if (format[*symbol] == '\0')
			return (-1);
		lenUnknow += write(1, "%%", 1);
		if (format[*symbol - 1] == ' ')
			lenUnknow += write(1, " ", 1);
		else if (width)
		{
			--(*symbol);
			while (format[*symbol] != ' ' && format[*symbol] != '%')
				--(*symbol);
			if (format[*symbol] == ' ')
				--(*symbol);
			return (1);
		}
		lenUnknow += write(1, &format[*symbol], 1);
		return (lenUnknow);
	}
	return (count);
}
