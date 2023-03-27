#include "main.h"

/**
 * _printf -> this function print to standout output
 *
 * @format: format string
 * Return: the total number of chracted bytes printed
 */

int _printf(const char *format, ...)
{
    int totalChar, returnChar = 0, index;
    int precision, width, flags, size, buffer_index = 0;
    char buffer[BUFFER_SIZE];
    va_list args;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (index = 0; format && format[index] != '\0'; index++)
    {
        if (format[index] != '%')
        {
            buffer[buffer_index++] = format[index];
            if (buffer_index == BUFFER_SIZE)
                print_buffer(buffer, &buffer_index);
            totalChar++;
        }
        else
        {
            print_buffer(buffer, &buffer_index);
            flags = get_flags(format, &index);
            width = get_width(format, &index, args);
            precision = get_precision(format, &index, args);
            size = get_size(format, &index);
            ++index;
            returnChar = handle_print(format, &index, args, buffer, flags, width, precision, size);
            if (returnChar == -1)
            {
                return (-1);
            }
            totalChar += returnChar;
        }
    }

    print_buffer(buffer, &buffer_index);

    va_end(args);

    return (totalChar);
}