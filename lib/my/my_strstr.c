/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_strstr
*/

#include "my.h"
#include <stddef.h>

int is_in_char(char *str, char const *to_find, int pos)
{
    int i = 0;

    while (to_find[i] != '\0') {
        if (str[pos + i] != to_find[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int size_str = my_strlen(str);
    int size_to_find = my_strlen(to_find);

    if (size_to_find == 0) {
        return str;
    }
    while (i <= size_str - size_to_find) {
        if (is_in_char(str, to_find, i)) {
            return &str[i];
        }
        i++;
    }
    return NULL;
}
