/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// documentation in op.c
int func_ld(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    int value = 0;

    if (number_args != 2)
        return 0;
    if (args[1].int_val < 1 || args[1].int_val > 16)
        return 0;
    if (args[0].type == T_IND)
        value = read_int(core, (proc_arg->proc->tmp_index +
            (args[0].int_val % IDX_MOD)) % MEM_SIZE);
    else
        value = ((args[0].int_val % IDX_MOD) % MEM_SIZE);
    proc_arg->proc->registers[args[1].int_val - 1] = value;
    if (value == 0)
        proc_arg->proc->carry = true;
    else
        proc_arg->proc->carry = false;
    return 0;
}
