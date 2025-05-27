/*
** EPITECH PROJECT, 2025
** my_isnumber.c
** File description:
** return 1 if a str is a number else 0
*/

#include "my.h"

int is_number(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    if (str[0] == '-')
        i++;
    for (; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
