/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// documentation in op.c
int func_zjmp(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    if (number_args != 1)
        return 0;
    if (args[0].type != T_DIR || proc_arg->proc->carry == false)
        return 0;
    proc_arg->proc->index = ((proc_arg->proc->tmp_index +
        (args[0].short_val % IDX_MOD)) % MEM_SIZE);
    return 0;
}
