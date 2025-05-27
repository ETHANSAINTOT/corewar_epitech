/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_find_prime_sup
*/

#include "my.h"

int find_sup(int nb)
{
    int i = nb;

    while (my_isprime(i) == 0) {
        i++;
    }
    return i;
}

int my_find_prime_sup(int nb)
{
    if (nb > 2147483647) {
        return 0;
    } else if (nb < 0) {
        return 2;
    } else {
        return find_sup(nb);
    }
    return 0;
}
