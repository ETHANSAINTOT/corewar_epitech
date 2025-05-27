/*
** EPITECH PROJECT, 2025
** tty_check.c
** File description:
** Check if the programm is running in tty
*/

#include "my.h"

int contains_word(char **array, const char *word)
{
    if (array == NULL) {
        return 0;
    }
    for (int i = 0; array[i] != NULL; i++) {
        if (my_strstr(array[i], word) != NULL) {
            return 1;
        }
    }
    return 0;
}

int is_a_tty(char **env)
{
    if (contains_word(env, "DISPLAY") == 0) {
        mini_printf("Impossible to load, you are in tty.\n");
        return 84;
    }
    return 0;
}
