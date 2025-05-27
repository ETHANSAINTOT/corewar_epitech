/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_getnbr
*/

#include "my.h"

int give_number(int i, long result, char const *str, int neg)
{
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        if (result > 2147483647 || result < -2147483648) {
            return 0;
        }
        i++;
    }
    return (int)(result * neg);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    long result = 0;

    while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            neg *= -1;
        }
        i++;
    }
    return give_number(i, result, str, neg);
}
