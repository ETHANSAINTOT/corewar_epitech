/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_compute_square_root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    for (int i = 0; i * i <= nb; i++) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
