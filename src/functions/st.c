/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// documentation in op.c
int func_st(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    int *registers = proc_arg->proc->registers;
    int d = 0;
    process_t *proc = proc_arg->proc;

    if (number_args != 2)
        return 0;
    if (args[0].int_val < 1 || args[0].int_val > REG_NUMBER ||
        (args[1].type == 1 &&
        (args[1].int_val < 1 || args[1].int_val > REG_NUMBER)))
        return 0;
    if (args[1].type == 1)
        registers[args[1].int_val - 1] = registers[args[0].int_val - 1];
    else {
        d = ((proc->tmp_index + (args[1].short_val) % IDX_MOD) % MEM_SIZE);
        if (d < 0 || d > (MEM_SIZE + 1))
            return 0;
        write_int(core, proc->tmp_index + args[1].short_val,
            &registers[args[0].int_val - 1]);
    }
    return 0;
}
