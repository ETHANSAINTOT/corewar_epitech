/*
** EPITECH PROJECT, 2024
** C file
** File description:
** mini_printf.c
*/

#include "corewar.h"

// write char
static void my_putchar(char c)
{
    write(1, &c, 1);
}

// write number
static int my_put_nbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
    }
    my_putchar('0' + (n % 10));
    return 0;
}

// write string
static int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}

// check mini printf flag
static void check_flag(char const *format, int *i, int *count, va_list list)
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

// print string with format
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
