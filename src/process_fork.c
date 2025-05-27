/*
** EPITECH PROJECT, 2024
** C file
** File description:
** mini_printf.c
*/

#include "corewar.h"

// realloc robot process list
static void *secure_realloc(void *pointer, size_t size)
{
    pointer = realloc(pointer, size);
    if (pointer == NULL){
        return NULL;
    }
    return pointer;
}

// copy registers
static void copy_reg(int *reg1, int *reg2)
{
    for (int i = 0; i < REG_NUMBER; i++)
        reg1[i] = reg2[i];
}

// fork process
int robot_fork(robot_t *robot, process_t *procs, int offset)
{
    process_t *lst = NULL;

    robot->process_number += 1;
    lst = secure_realloc(robot->process, sizeof(process_t) *
        robot->process_number);
    if (lst == NULL){
        robot->process_number -= 1;
        return 0;
    }
    robot->process = lst;
    memset(&robot->process[robot->process_number - 1], 0, sizeof(process_t));
    robot->process[robot->process_number - 1].carry = procs->carry;
    robot->process[robot->process_number - 1].index = ((
        procs->tmp_index + offset) % MEM_SIZE);
    copy_reg(robot->process[robot->process_number - 1].registers,
        procs->registers);
    robot->process[robot->process_number - 1].size = procs->size;
    robot->process[robot->process_number - 1].started = false;
    return 0;
}
