#include "main.h"

int get_flags(const char *format, int *index)
{
    int k, i;
    int flags = 0;
    const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARRAY[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};

    for (i = *index + 1; format[i] != '\0'; i++)
    {
        for (k = 0; FLAGS_ARRAY[k] != '\0'; k++)
        {
            if (format[i] == FLAGS_CHAR[k])
            {
                flags |= FLAGS_ARRAY[k];
                break;
            }
        }
        if (FLAGS_CHAR[k] == 0)
            break;
    }

    *index = i - 1;

    return (flags);
}