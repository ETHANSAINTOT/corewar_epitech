/*
** EPITECH PROJECT, 2024
** C file
** File description:
** mini_printf.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void check_flag(char const *format, int *i, int *count, va_list list)
{
    if (format[*i + 1] == 'd' || format[*i + 1] == 'i') {
        *count += my_put_nbr(va_arg(list, int));
        (*i)++;
    }
    if (format[*i + 1] == 's') {
        *count += my_putstr(va_arg(list, char *));
        (*i)++;
    }
    if (format[*i + 1] == 'c') {
        my_putchar((char) va_arg(list, int));
        (*count)++;
        (*i)++;
    }
    if (format[*i + 1] == '%') {
        my_putchar('%');
        (*count)++;
        (*i)++;
    }
}

int mini_printf(char const *format, ...)
{
    int i = 0;
    int count = 0;
    va_list list;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            check_flag(format, &i, &count, list);
        } else {
            my_putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(list);
    return count;
}
