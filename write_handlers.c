#include "main.h"

int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
    int index = 0;
    char padd = ' ';

    UNUSED(precision);
    UNUSED(size);

    if (flags & FLAG_ZERO)
        padd = '0';

    buffer[index++] = c;
    buffer[index] = '\0';

    if (width > 1)
    {
        buffer[BUFFER_SIZE - 1] = '\0';
        for (index = 0; index < width - 1; index++)
            buffer[BUFFER_SIZE - index - 2] = padd;

        if (flags & FLAG_MINUS)
            return (write(1, &buffer[0], 1) +
                    write(1, &buffer[BUFFER_SIZE - index - 1], width - 1));
        else
            return (write(1, &buffer[BUFFER_SIZE - index - 1], width - 1) +
                    write(1, &buffer[0], 1));
    }

    return (write(1, &buffer[0], 1));
}
