/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char var_temp;

    for (int i = 0; i < len / 2; i++) {
        var_temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = var_temp;
    }
    return str;
}
