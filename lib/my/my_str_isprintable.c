/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_str_isprintable
*/

#include "my.h"

int find_nb_print_char(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 126) {
            return 0;
        }
        i++;
    }
    return 1;
}

int my_str_isprintable(char const *str)
{
    if (my_strlen(str) == 0) {
        return 1;
    } else {
        return find_nb_print_char(str);
    }
}
