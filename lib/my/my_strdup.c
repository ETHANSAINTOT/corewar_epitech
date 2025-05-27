/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** Like strdup form libc
** Creator : ethan.saintot@epitech.eu
*/

#include "my.h"

char *my_strdup(const char *src)
{
    char *dest = malloc(my_strlen(src) + 1);

    if (!dest) {
        return NULL;
    }
    my_strcpy(dest, src);
    return dest;
}
