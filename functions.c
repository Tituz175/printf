#include "main.h"



int print_char(va_list type, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(type, int);
    return (handle_write_char(c, buffer, flags, width, precision, size));
}