/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_sort_int_array
*/

#include "my.h"

void my_sort_int_array(int *tab, int size)
{
    int x = 0;
    int j = 0;

    for (int i = 1; i <= size - 1; i++) {
        x = tab[i];
        j = i;
        while (j > 0 && tab[j - 1] > x) {
            tab[j] = tab[j - 1];
            j = j - 1;
        }
        tab[j] = x;
    }
}
