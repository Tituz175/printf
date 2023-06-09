#include "main.h"

/**
 * get_size -> this function handle the given size
 * @format: pointer to the given string
 * @index: pointer to the index of the given string
 * Return: the size
 */

int get_size(const char *format, int *index)
{
	int i = *index + 1;
	int size = 0;

	if (format[i] == 'l')
	{
		size = SIZE_LONG;
	}
	else if (format[i] == 'h')
	{
		size = SIZE_SHORT;
	}
	if (size == 0)
	{
		*index = i - 1;
	}
	else
	{
		*index = i;
	}

	return (size);
}
