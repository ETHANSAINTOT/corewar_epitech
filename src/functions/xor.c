/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// get value
static int func_xor_get_value(corewar_t *core, type_t *arg,
    int *reg, process_t *proc)
{
    if (arg->type == 1)
        return reg[arg->int_val - 1];
    else if (arg->type == 2)
        return arg->int_val;
    else
        return read_int(core, proc->tmp_index + arg->short_val);
    return 0;
}

// check args
static bool xor_check_arg(type_t args[])
{
    if (((args[0].int_val < 1 || args[0].int_val > REG_NUMBER) &&
        args[0].type == 1) ||
        ((args[1].int_val < 1 || args[1].int_val > REG_NUMBER) &&
        args[1].type == 1) ||
        (args[2].int_val < 1 || args[2].int_val > REG_NUMBER ||
        args[2].type != 1))
        return false;
    return true;
}

// documentation in op.c
int func_xor(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    int *registers = proc_arg->proc->registers;
    process_t *proc = proc_arg->proc;
    int val[2];

    if (number_args != 3)
        return 0;
    if (xor_check_arg(args) == false)
        return 0;
    val[0] = func_xor_get_value(core, &args[0], registers, proc);
    val[1] = func_xor_get_value(core, &args[0], registers, proc);
    registers[args[2].int_val - 1] = (val[0] ^ val[1]);
    if ((val[0] ^ val[1]) == 0)
        proc->carry = true;
    else
        proc->carry = false;
    return 0;
}
