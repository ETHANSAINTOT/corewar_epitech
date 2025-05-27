/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// check arguments
static bool ldi_check_arg(type_t args[])
{
    if (args[0].type == 1 && (args[0].int_val < 1 ||
        args[0].int_val > REG_NUMBER))
        return false;
    if (((args[0].type == 1 && (args[0].int_val < 1 ||
        args[0].int_val > REG_NUMBER)) ||
        args[0].type == 4))
        return false;
    if (args[0].type != 1 || (args[0].int_val < 1 ||
        args[0].int_val > REG_NUMBER))
        return false;
    return true;
}

// get value
static int get_value_arg(corewar_t *core, type_t *arg, arg_t *proc_arg)
{
    if (arg->type == T_IND)
        return read_int(core, (proc_arg->proc->tmp_index +
        (arg->int_val % IDX_MOD)) % MEM_SIZE);
    else if (arg->type == T_REG)
        return ((arg->int_val % IDX_MOD) % MEM_SIZE);
    else
        return ((arg->short_val % IDX_MOD) % MEM_SIZE);
    return 0;
}

// documentation in op.c
int func_ldi(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    int value = 0;

    if (number_args != 3 || !ldi_check_arg(args))
        return 0;
    value = get_value_arg(core, &args[0], proc_arg);
    value = read_int(core, ((proc_arg->proc->tmp_index +
        (value % IDX_MOD)) % MEM_SIZE)) +
        get_value_arg(core, &args[1], proc_arg);
    value = read_int(core, ((proc_arg->proc->tmp_index +
        (value % IDX_MOD)) % MEM_SIZE));
    proc_arg->proc->registers[args[2].int_val - 1] = value;
    if (value == 0)
        proc_arg->proc->carry = true;
    else
        proc_arg->proc->carry = false;
    return 0;
}
