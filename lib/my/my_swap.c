/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_swap
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
