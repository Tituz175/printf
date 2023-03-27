#include "main.h"

int handle_print(const char *format, int *symbol, va_list args, char buffer[], int flags, int width, int precision, int size)
{
    int index, count = 0;

    function functionsArray[] = {
        {'c', print_char},
        {'\0', NULL}};

    for (index = 0; functionsArray[index].fuctionSymbol != '\0'; index++)
    {
        if (format[*symbol] == functionsArray[index].fuctionSymbol)
        {
            count = functionsArray[index].function(args, buffer, flags, width, precision, size);
            return (count);
        }
    }

    return (count);
}