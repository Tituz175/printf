#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

#define SIZE_LONG 2
#define SIZE_SHORT 1

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)

/**
 * struct functions - identifiers for my printf function
 * @char: input function symbol
 * @function: function for input symbol
 */

typedef struct functions
{
    char fuctionSymbol;
    int (*function)(va_list type, char buffer[], int flags, int width, int precision, int size);
} function;

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int print_char(va_list types, char buffer[],
               int flags, int width, int precision, int size);


int handle_write_char(char c, char buffer[],
                      int flags, int width, int precision, int size);

                      
int handle_print(const char *format, int *symbol, va_list args, char buffer[], int flags, int width, int precision, int size);

int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);


int is_digit(char c);

#endif