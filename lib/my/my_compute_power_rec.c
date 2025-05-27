/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_compute_power_rec
*/

#include "my.h"

int cal_pow_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    } else {
        return nb * cal_pow_rec(nb, p - 1);
    }
}

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    return cal_pow_rec(nb, p);
}
