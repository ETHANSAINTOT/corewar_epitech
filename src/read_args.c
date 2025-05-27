/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/
#include "corewar.h"


//read int in memory
int read_int(corewar_t *core, unsigned int start)
{
    void *value = malloc(4);
    int val = 0;

    if (value == NULL)
        return 0;
    ((char *) value)[0] = ((char *) core->memory)[start + 3];
    ((char *) value)[1] = ((char *) core->memory)[start + 2];
    ((char *) value)[2] = ((char *) core->memory)[start + 1];
    ((char *) value)[3] = ((char *) core->memory)[start];
    val = *(int *)value;
    free(value);
    return val;
}

// read short in memory
static int read_short(corewar_t *core, unsigned int start)
{
    void *value = malloc(2);
    short val = 0;

    if (value == NULL)
        return 0;
    ((char *) value)[0] = ((char *) core->memory)[start + 1];
    ((char *) value)[1] = ((char *) core->memory)[start];
    val = *(short *)value;
    free(value);
    return val;
}

// read function arguments
int read_args(corewar_t *core, process_t *proc, type_t *args,
    unsigned char inst)
{
    for (int i = 0; i < 4; i++){
        if (args[i].type == 0)
            continue;
        if (args[i].type == T_REG){
            args[i].int_val = ((char *) core->memory)[proc->index];
            proc->index = ((proc->index + 1) % MEM_SIZE);
        }
        if (args[i].type == (T_IND - 1) || (args[i].type == T_DIR &&
            is_dir_size_2(inst) == 2)){
            args[i].short_val = read_short(core, proc->index);
            proc->index = ((proc->index + 2) % MEM_SIZE);
        }
        if (args[i].type == T_DIR && is_dir_size_2(inst) == 4){
            args[i].int_val = read_int(core, proc->index);
            proc->index = ((proc->index + 4) % MEM_SIZE);
        }
    }
    return 0;
}
