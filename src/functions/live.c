/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

int func_live(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg)
{
    if (number_args != 1)
        return 0;
    if (args[0].int_val < 1 || args[0].int_val > 4 ||
        get_robots_idx(core, args[0].int_val) == -1 ||
        core->robots[get_robots_idx(core, args[0].int_val)].is_dead == true)
        return 0;
    core->robots[get_robots_idx(core, args[0].int_val)].is_alive = true;
    mini_printf("The player %d(%s) is alive.\n",
        args[0].int_val, core->robots[get_robots_idx(core,
        args[0].int_val)].header.prog_name);
    core->last_live_robot = args[0].int_val;
    core->called_live += 1;
    proc_arg->inst = proc_arg->inst;
    return 0;
}
