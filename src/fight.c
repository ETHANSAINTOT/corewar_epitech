/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// get args number of the instruction
unsigned int get_functions_nbr_arg(unsigned char id)
{
    extern const op_t op_tab[];

    for (int i = 0; op_tab[i].code != 0; i++){
        if (op_tab[i].code != id)
            continue;
        return op_tab[i].nbr_args;
    }
    return 0;
}

// get instruction wait cycle
unsigned int get_inst_cost(unsigned char id)
{
    extern const op_t op_tab[];

    for (int i = 0; op_tab[i].code != 0; i++){
        if (op_tab[i].code != id)
            continue;
        return op_tab[i].nbr_cycles;
    }
    return 0;
}

// wait cycle before executing instruction
static bool wait_cycle(corewar_t *core, process_t *proc, unsigned char id)
{
    unsigned int inst_cycle_cost = get_inst_cost(id);

    if (proc->target_cycle == 0){
        proc->target_cycle = (core->cycle + inst_cycle_cost);
        return true;
    }
    if (core->cycle > proc->target_cycle){
        proc->target_cycle = 0;
        return false;
    }
    return true;
}

// execute if instruction dont have encoding byte
static int get_no_encoding_byte(type_t *args, unsigned char inst)
{
    int index = 0;
    extern const op_t op_tab[];

    while (op_tab[index].code != inst){
        if (op_tab[index].code == 0){
            index = -1;
            break;
        }
        index++;
    }
    if (index == -1)
        return 0;
    for (int i = 0; i < op_tab[index].nbr_args; i++){
        args[i].type = op_tab[index].type[i];
    }
    return 0;
}

// check if DIR size is 2 or 4
char is_dir_size_2(char inst)
{
    char inst_code[] = {9, 10, 11, 12, 14, 15, 0};

    for (int i = 0; inst_code[i] != 0; i++){
        if (inst_code[i] == inst)
            return 2;
    }
    return 4;
}

// execution functions
static int call_functions(corewar_t *core, int number_args,
    type_t *args, arg_t *proc_arg)
{
    extern const function_t functions[];

    for (int i = 0; functions[i].code != 0; i++){
        if (functions[i].code != proc_arg->inst)
            continue;
        return functions[i].functions(core, number_args, args, proc_arg);
    }
    return 0;
}

// execute process
static int handle_inst(corewar_t *core, process_t *proc,
    unsigned char inst_id, robot_t *robot)
{
    type_t args[4];
    arg_t proc_arg = {inst_id, robot, proc};
    unsigned char enc_byte = 0;

    proc->tmp_index = proc->index;
    memset(&args, 0, sizeof(type_t) * 4);
    if (has_enc_byte(inst_id)){
        proc->index = ((proc->index + 1) % MEM_SIZE);
        enc_byte = ((char *) core->memory)[proc->index];
        show_encoding_byte(enc_byte, args);
    } else {
        get_no_encoding_byte(args, inst_id);
    }
    proc->index = ((proc->index + 1) % MEM_SIZE);
    read_args(core, proc, args, inst_id);
    call_functions(core, get_functions_nbr_arg(inst_id), args, &proc_arg);
    return 0;
}

//process loop
static int process_loop(corewar_t *core, robot_t *robot, process_t *proc)
{
    unsigned char inst = 0;

    if (proc->started == false){
        proc->started = true;
        return 0;
    }
    inst = ((char *) core->memory)[proc->index];
    if (wait_cycle(core, proc, inst))
        return 0;
    if (inst != 0){
        handle_inst(core, proc, inst, robot);
    }
    if (inst == 0)
        proc->index = ((proc->index + 1) % MEM_SIZE);
    return 0;
}

// robot loop
static int robots_loop(corewar_t *core, robot_t *robot)
{
    if (robot->is_dead == true)
        return 0;
    for (unsigned int i = 0; i < robot->process_number; i++)
        process_loop(core, robot, &robot->process[i]);
    if ((core->cycle % core->cycle_die) == 0 && !is_finished(core)){
        if (robot->is_alive == false)
            robot->is_dead = true;
        robot->is_alive = false;
    }
    return 0;
}

// cycle loop
int fight(corewar_t *core)
{
    while (!is_finished(core) && (core->flgs.dumpflg == false ||
        (core->cycle <= core->flgs.dump))){
        core->cycle += 1;
        for (int i = 0; i < core->robots_number; i++)
            robots_loop(core, &core->robots[i]);
        core->cycle_die -= ((int) (core->called_live / NBR_LIVE)
            * CYCLE_DELTA);
        core->called_live = (core->called_live % NBR_LIVE);
        if (core->cycle_die < 1)
            core->cycle_die = 1;
    }
    print_winner(core);
    if (core->flgs.dumpflg == true)
        print_memory(core);
    return 0;
}
