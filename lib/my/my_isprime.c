/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_isprime
*/

#include "my.h"

int my_isprime(int nb)
{
    int div = 0;

    if (nb <= 1) {
        return 0;
    }
    for (int i = 1; i <= nb; i++) {
        if (nb % i == 0) {
            div++;
        }
    }
    if (div == 2) {
        return 1;
    }
    return 0;
}
