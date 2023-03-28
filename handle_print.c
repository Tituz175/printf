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
	int index, count = 0;

	function functionsArray[] = {
		{'c', print_char},
		{'\0', NULL}};

	for (index = 0; functionsArray[index].functionSymbol != '\0'; index++)
	{
		if (format[*symbol] == functionsArray[index].functionSymbol)
		{
			count = functionsArray[index].function(args,
								buffer,
								flags,
								width,
								precision,
								size);
			return (count);
		}
	}

	return (count);
}
