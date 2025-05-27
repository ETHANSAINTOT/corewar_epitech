/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include "my.h"

int is_alpha_num(char c)
{
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z'));
}

int count_word(char const *str)
{
    int in_word = 0;
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (is_alpha_num(str[i]) && in_word == 0) {
            in_word = 1;
            count++;
        }
        if (!is_alpha_num(str[i])) {
            in_word = 0;
        }
        i++;
    }
    return count;
}

static char *my_strndup(const char *src, int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));
    int i = 0;

    if (dest == NULL)
        return NULL;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

static void first_if(char const *str, int i, int *in_word, int *start)
{
    if (is_alpha_num(str[i]) && (*in_word) == 0) {
        *in_word = 1;
        *start = i;
    }
}

static void increment_j_and_in_word(int *j, int *in_word)
{
    (*j)++;
    *in_word = 0;
}

char **my_str_to_word_array(char const *str)
{
    char **tab = malloc(sizeof(char *) * (count_word(str) + 1));
    int i = 0;
    int j = 0;
    int in_word = 0;
    int start = 0;

    while (str[i] != '\0') {
        first_if(str, i, &in_word, &start);
        if (!is_alpha_num(str[i]) && in_word == 1) {
            tab[j] = my_strndup(&str[start], i - start);
            increment_j_and_in_word(&j, &in_word);
        }
        i++;
    }
    if (in_word == 1) {
        tab[j] = my_strndup(&str[start], i - start);
        j++;
    }
    tab[j] = NULL;
    return tab;
}
