/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_strlowcase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
    return str;
}
