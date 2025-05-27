/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *str, int n)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (str[j] != '\0' && j < n) {
        dest[i] = str[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
