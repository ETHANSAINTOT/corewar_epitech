/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// documentation in op.c
int func_aff(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    if (number_args != 1)
        return 0;
    if (args[0].int_val < 1 || args[0].int_val > REG_NUMBER)
        return 0;
    mini_printf("%c\n",
        proc_arg->proc->registers[args[0].int_val - 1]);
    return 0;
}
