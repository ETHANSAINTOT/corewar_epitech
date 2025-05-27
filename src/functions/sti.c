/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"
/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

static int get_arg_value(corewar_t *core, type_t *arg,
    arg_t *data)
{
    if (arg->type == 1)
        return data->proc->registers[arg->int_val - 1];
    else if (arg->type == 2){
        if (is_dir_size_2(data->inst))
            return arg->short_val;
        return arg->int_val;
    } else
        return read_int(core, data->proc->tmp_index + arg->short_val);
    return 0;
}

// documentation in op.c
int func_sti(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    int *registers = proc_arg->proc->registers;
    int d = 0;
    process_t *proc = proc_arg->proc;

    if (number_args != 3)
        return 0;
    if (args[0].int_val < 1 || args[0].int_val > REG_NUMBER ||
        (args[1].type == 1 &&
        (args[1].int_val < 1 || args[1].int_val > REG_NUMBER)) ||
        (args[2].type == 4 || (args[2].type == 1 &&
        (args[1].int_val < 1 || args[1].int_val > REG_NUMBER))))
        return 0;
    if (args[1].type == 1)
        registers[args[1].int_val - 1] = registers[args[0].int_val - 1];
    d = get_arg_value(core, &args[0], proc_arg);
    write_int(core, (proc_arg->proc->tmp_index +
        get_arg_value(core, &args[1], proc_arg) +
        get_arg_value(core, &args[2], proc_arg)), &d);
    return 0;
}
