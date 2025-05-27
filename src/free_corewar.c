/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// free all
int free_corewar(corewar_t *core, int ret_value)
{
    if (core->memory != NULL)
        free(core->memory);
    for (int i = 0; i < core->robots_number; i++)
        free(core->robots[i].process);
    return ret_value;
}
