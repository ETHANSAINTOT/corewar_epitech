/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/
#include "corewar.h"
#include <stdbool.h>
#include <unistd.h>


const function_t functions[] = {
    {1, func_live},
    {2, func_ld},
    {3, func_st},
    {4, func_add},
    {5, func_sub},
    {6, func_and},
    {7, func_or},
    {8, func_xor},
    {9, func_zjmp},
    {10, func_ldi},
    {11, func_sti},
    {12, func_fork},
    {13, func_lld},
    {14, func_lldi},
    {15, func_lfork},
    {16, func_aff},
    {0, 0}
};

int get_robots_idx(corewar_t *core, unsigned int rid)
{
    for (int i = 0; i < 4; i++){
        if (core->robots[i].robot_id == rid)
            return i;
    }
    return -1;
}

// try to know if instruction have encoding byte or not
bool has_enc_byte(unsigned char id)
{
    extern const op_t op_tab[];
    bool found = false;
    char val = 0;

    for (int i = 0; op_tab[i].code != 0; i++){
        if (op_tab[i].code != id)
            continue;
        found = true;
        for (int i2 = 0; i2 < op_tab[i].nbr_args; i2++)
            val += (op_tab[i].type[i2] != 2 &&
                op_tab[i].type[i2] != 4);
        break;
    }
    if (found == false || val == 0)
        return false;
    return true;
}

// chnage int order (little/big)
int change_int_order(int num)
{
    int result = 0;

    for (int i = 0; i < 4; i++) {
        result = (result | ((num >> (i * 8)) & 0xFF) <<
            (((sizeof(num) -1) - i) * 8));
    }
    return result;
}

// try to get encoding byte
int show_encoding_byte(char value, type_t args[])
{
    int res = 0;
    unsigned char list[] = {(value >> 6) & 0x03, (value >> 4) & 0x03,
        (value >> 2) & 0x03, (value) & 0x03};
    int test2[] = {0, 1, DIR_SIZE, IND_SIZE};

    for (int i = 0; i < 4; i++){
        if (list[i] == 0)
            args[i].type = 0;
        else
            args[i].type = list[i];
        res += (test2[list[i]]);
    }
    return res;
}

// init process for each robots
static int init_process(corewar_t *core)
{
    for (int i = 0; i < core->robots_number; i++){
        core->robots[i].process = malloc(sizeof(process_t));
        if (core->robots[i].process == NULL)
            continue;
        memset(&core->robots[i].process[0], 0, sizeof(process_t));
        core->robots[i].process[0].started = true;
        core->robots[i].process[0].index = (i * core->mem_offset);
        core->robots[i].process[0].size = core->mem_offset;
        core->robots[i].process_number = 1;
        core->robots[i].process[0].registers[0] = (i + 1);
    }
    return 0;
}

// main
int main(int argc, char **argv)
{
    corewar_t core;
    int argi = 1;

    memset(&core, 0, sizeof(corewar_t));
    core.last_live_robot = -1;
    argi += set_dump_flag(&core, argv, argi, argc);
    core.cycle_die = CYCLE_TO_DIE;
    core.memory = malloc(MEM_SIZE);
    if (core.memory == NULL)
        return 84;
    memset(core.memory, 0, MEM_SIZE);
    for (int i = 0; i < 4; i++)
        memset(&core.robots[i], 0, sizeof(robot_t));
    core.mem_offset = (MEM_SIZE / get_robot_number(argc, argv, &core, argi));
    if (load_robots(argc, argv, &core, argi) == 84)
        return free_corewar(&core, 84);
    init_process(&core);
    fight(&core);
    return free_corewar(&core, 0);
}
