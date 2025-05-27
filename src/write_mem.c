/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/
#include "corewar.h"


// write int in memeory
int write_int(corewar_t *core, unsigned int start, void *value)
{
    if (value == NULL)
        return 0;
    ((char *) core->memory)[(start + 3) % MEM_SIZE] = ((char *) value)[0];
    ((char *) core->memory)[(start + 2) % MEM_SIZE] = ((char *) value)[1];
    ((char *) core->memory)[(start + 1) % MEM_SIZE] = ((char *) value)[2];
    ((char *) core->memory)[(start) % MEM_SIZE] = ((char *) value)[3];
    return 0;
}

// convert int to hex string
static void to_hex(unsigned int value, char *out)
{
    const char *hex = "0123456789ABCDEF";

    out[0] = hex[(value >> 4) & 0xF];
    out[1] = hex[value & 0xF];
    out[2] = '\0';
}

// print (dump) memory
void print_memory(corewar_t *core)
{
    const unsigned char *bytes = (const unsigned char *)core->memory;
    char hex[3];

    for (size_t i = 0; i < MEM_SIZE; i++) {
        to_hex(bytes[i], hex);
        write(1, hex, 2);
        if ((i + 1) % 32 == 0 || i + 1 == MEM_SIZE) {
            write(1, "\n", 1);
        }
    }
}
