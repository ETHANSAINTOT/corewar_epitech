/*
** EPITECH PROJECT, 2024
** C file
** File description:
** my_showstr
*/

#include "my.h"

int is_printable_char(char c)
{
    return (c >= 32 && c <= 126);
}

char int_to_hex_char(int num)
{
    return (num >= 0 && num <= 9) ? ('0' + num) : ('a' + (num - 10));
}

void print_hex_representation(char c)
{
    char buffer[3];
    unsigned char value = (unsigned char)c;

    buffer[0] = int_to_hex_char((value >> 4) & 0xF);
    buffer[1] = int_to_hex_char(value & 0xF);
    buffer[2] = '\0';
    my_putchar('\\');
    my_putchar(buffer[0]);
    my_putchar(buffer[1]);
}

int check_if(int all_printable, char const *str, int i)
{
    if (is_printable_char(str[i]) == 1) {
        my_putchar(str[i]);
    } else {
        all_printable = 0;
        print_hex_representation(str[i]);
    }
    return all_printable;
}

int my_showstr(char const *str)
{
    int i = 0;
    int all_printable = 1;

    while (str[i] != '\0') {
        all_printable = check_if(all_printable, str, i);
        i++;
    }
    return all_printable;
}
