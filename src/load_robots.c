/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/
#include "corewar.h"
#include <stdbool.h>
#include <unistd.h>

// write robot in memory
static int fill_void(int start, int size, void *input, void *target)
{
    for (int i = start; i < (start + size); i++)
        ((char *)target)[i % MEM_SIZE] = ((char *)input)[i - start];
    return 0;
}

static void set_robots_id(corewar_t *core, robot_t *robot, int id)
{
    if (!core->robot_flg.robot_number_bool){
        robot->robot_id = (id + 1);
        return;
    }
    if (get_robots_idx(core, core->robot_flg.robot_number) != -1){
        robot->robot_id = (id + 1);
        return;
    }
    robot->robot_id = core->robot_flg.robot_number;
}

static void put_program_in_memory(corewar_t *core, robot_t *robot,
    FILE *f, char *robot_mem)
{
    robot->mem_size = (core->mem_offset);
    fread(robot_mem, change_int_order(robot->header.prog_size),
    1, f);
    fill_void(robot->mem_index, change_int_order(
        robot->header.prog_size), robot_mem, core->memory);
    free(robot_mem);
}

static bool check_cor_file(FILE *f)
{
    header_t checker;
    unsigned long size = 0;

    fseek(f, 0, SEEK_END);
    size = f->_offset;
    fseek(f, 0, SEEK_SET);
    if (size < sizeof(header_t))
        return false;
    fread(&checker, sizeof(header_t), 1, f);
    fseek(f, 0, SEEK_SET);
    if (checker.magic != change_int_order(COREWAR_EXEC_MAGIC))
        return false;
    return true;
}

// load each robot
static int load_one_robot(corewar_t *core, robot_t *robot, FILE *f, int i)
{
    void *robot_mem = NULL;

    if (check_cor_file(f) == false)
        return 84;
    fread(&robot->header, sizeof(header_t), 1, f);
    set_robots_id(core, robot, i);
    robot_mem = malloc(change_int_order(robot->header.prog_size));
    if (robot_mem == NULL){
        free(robot_mem);
        return 84;
    }
    if (core->robot_flg.mem_offset_bool)
        robot->mem_index = (core->robot_flg.mem_offset % MEM_SIZE);
    else
        robot->mem_index = (i * core->mem_offset);
    put_program_in_memory(core, robot, f, robot_mem);
    return 0;
}

// return number of robots
int get_robot_number(int argc, char **argv, corewar_t *core, int argi)
{
    for (int i = (argi); i < (argc); i++){
        i += set_robot_flag(NULL, argv, i, argc);
        core->robots_number += 1;
    }
    return core->robots_number;
}

// load all robots
int load_robots(int argc, char **argv, corewar_t *core, int argi)
{
    FILE *f = NULL;
    int counter = 0;

    if (core->robots_number < 1 || core->robots_number > 4)
        return 84;
    for (int i = (argi - 1); argv[i + 1] != NULL; i++){
        i += set_robot_flag(&core->robot_flg, argv, i + 1, argc);
        f = fopen(argv[i + 1], "rb");
        if (f == NULL)
            return 84;
        if (load_one_robot(core, &core->robots[counter], f,
            counter) == 84){
            fclose(f);
            return 84;
        }
        fclose(f);
        counter += 1;
    }
    return 0;
}
