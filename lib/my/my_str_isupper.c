/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_str_isupper
*/

#include "my.h"

int find_nb_up(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'A' || str[i] > 'Z') {
            return 0;
        }
        i++;
    }
    return 1;
}

int my_str_isupper(char const *str)
{
    if (my_strlen(str) == 0) {
        return 1;
    } else {
        return find_nb_up(str);
    }
}
