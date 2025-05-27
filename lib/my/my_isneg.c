/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    return 0;
}
