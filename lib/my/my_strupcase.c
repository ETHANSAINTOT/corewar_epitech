/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_strupcase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}
