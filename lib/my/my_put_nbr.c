/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
    }
    my_putchar('0' + (n % 10));
    return 0;
}
