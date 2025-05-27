/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// check if all robot dead or only 1 survivor
bool is_finished(corewar_t *core)
{
    int len = core->robots_number;
    int num = 0;

    for (int i = 0; i < len; i++){
        if (core->robots[i].is_dead)
            num++;
    }
    if (num == len || (num + 1) == len)
        return true;
    return false;
}

// print winner robot
int print_winner(corewar_t *core)
{
    if (core->last_live_robot < 0){
        mini_printf("The player 0() has won.\n");
        return 0;
    }
    mini_printf("The player %d(%s) has won.\n",
        (core->last_live_robot),
        core->robots[get_robots_idx(core,
        core->last_live_robot)].header.prog_name);
    return 0;
}
