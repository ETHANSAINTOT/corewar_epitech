/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_str_islower
*/

#include "my.h"

int find_nb_low(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 'a' || str[i] > 'z') {
            return 0;
        }
        i++;
    }
    return 1;
}

int my_str_islower(char const *str)
{
    if (my_strlen(str) == 0) {
        return 1;
    } else {
        return find_nb_low(str);
    }
}
