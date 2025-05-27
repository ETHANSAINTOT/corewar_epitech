/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_strcapitalize
*/

#include "my.h"

void change_letter(char *str, int i)
{
    if ((str[i] >= 'a' && str[i] <= 'z') && (i == 0 || (!(str[i - 1] >= 'a'
        && str[i - 1] <= 'z') && !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')
        && !(str[i - 1] >= '0' && str[i - 1] <= '9')))) {
        str[i] -= 32;
    } else if ((str[i] >= 'A' && str[i] <= 'Z') && !(i == 0 || (!
        (str[i - 1] >= 'a' && str[i - 1] <= 'z') && !(str[i - 1] >= 'A'
        && str[i - 1] <= 'Z') && !(str[i - 1] >= '0'
        && str[i - 1] <= '9')))) {
        str[i] += 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        change_letter(str, i);
        i++;
    }
    return str;
}
