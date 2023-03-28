#include "main.h"

/**
 * print_char -> this function print char
 * @type: list of args
 * @buffer: hold the char
 * @flags: the given flag
 * @width: the given width
 * @precision: the given precision
 * @size: the given size
 * Return: the number of char.
 */

int print_char(va_list type, char buffer[], int flags,
int width, int precision, int size)
{
	char c = va_arg(type, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
