/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// documentation in op.c
int func_lfork(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    if (number_args != 1)
        return 0;
    if (args[0].type != T_DIR)
        return 0;
    robot_fork(proc_arg->robot, proc_arg->proc, args[0].short_val);
    return 0;
}
