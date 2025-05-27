/*
** EPITECH PROJECT, 2025
** B-CPE-101:C_workshop_lib
** File description:
** char_star_star_len
*/

#include <stdlib.h>

int char_star_star_len(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }
    return i;
}
