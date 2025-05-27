/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_str_isnum
*/

#include "my.h"

int find_nb_num(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

int my_str_isnum(char const *str)
{
    if (my_strlen(str) == 0) {
        return 1;
    } else {
        return find_nb_num(str);
    }
}
