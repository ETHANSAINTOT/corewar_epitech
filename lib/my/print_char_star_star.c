/*
** EPITECH PROJECT, 2025
** print_char**.c
** File description:
** print a char **
*/

#include "my.h"

int print_char_star_star(char **array)
{
    if (array == NULL) {
        return 84;
    }
    for (int i = 0; array[i] != NULL; i++) {
        mini_printf("%s\n", array[i]);
    }
    return 0;
}
