/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// documentation in op.c
int func_sub(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    int *registers = proc_arg->proc->registers;
    process_t *proc = proc_arg->proc;
    int d = 0;

    if (number_args != 3)
        return 0;
    if (args[0].int_val < 1 || args[0].int_val > REG_NUMBER ||
        args[1].int_val < 1 || args[1].int_val > REG_NUMBER ||
        args[2].int_val < 1 || args[2].int_val > REG_NUMBER)
        return 0;
    if (args[0].type != 1 || args[1].type != 1 || args[2].type != 1)
        return 0;
    d = (registers[args[0].int_val - 1] - registers[args[1].int_val - 1]);
    registers[args[2].int_val - 1] = d;
    if (d == 0)
        proc->carry = true;
    else
        proc->carry = false;
    return 0;
}
