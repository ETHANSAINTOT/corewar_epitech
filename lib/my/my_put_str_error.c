/*
** EPITECH PROJECT, 2025
** C file
** File description:
** my_put_str_error
*/

#include "my.h"

void print_error(char const *str)
{
    write(2, str, my_strlen(str));
}
