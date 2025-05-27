/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#ifndef _COREWAR_
    #define _COREWAR_
    #include "op.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <string.h>
    #include <ncurses.h>
    #define UNUSED __attribute__ ((unused))

typedef struct type_s {
    unsigned char type;
    int int_val;
    short short_val;
} type_t;

typedef struct process_s {
    bool started;
    bool carry;
    bool dead;
    int registers[16];
    int index;
    int tmp_index;
    unsigned int size;
    long int target_cycle;
} process_t;

typedef struct robot_s {
    unsigned int robot_id;
    header_t header;
    process_t *process;
    unsigned int process_number;
    unsigned int mem_index;
    unsigned int mem_size;
    bool is_dead;
    bool is_alive;
} robot_t;

typedef struct robot_flg_s {
    bool mem_offset_bool;
    unsigned int mem_offset;
    bool robot_number_bool;
    unsigned int robot_number;
} robot_flg_t;

typedef struct core_flg_s {
    bool dumpflg;
    unsigned int dump;
} core_flg_t;

typedef struct corewar_s {
    robot_t robots[4];
    robot_flg_t robot_flg;
    core_flg_t flgs;
    int last_live_robot;
    unsigned char robots_number;
    void *memory;
    unsigned int mem_offset;
    unsigned int cycle;
    int cycle_die;
    unsigned int called_live;
} corewar_t;


typedef struct arg_s {
    unsigned char inst;
    robot_t *robot;
    process_t *proc;
} arg_t;


typedef struct function_s {
    unsigned char code;
    int (*functions) (corewar_t *core, int number_args, type_t args[],
        arg_t *proc_arg);
} function_t;
extern const function_t functions[];

bool is_finished(corewar_t *core);

//test
int show_encoding_byte(char value, type_t args[]);
int fight(corewar_t *core);
bool has_enc_byte(unsigned char id);
int print_winner(corewar_t *core);
unsigned int get_functions_nbr_arg(unsigned char id);
int read_args(corewar_t *core, process_t *proc, type_t *args,
    unsigned char inst);
char is_dir_size_2(char inst);
int read_int(corewar_t *core, unsigned int start);
int write_int(corewar_t *core, unsigned int start, void *value);
int free_corewar(corewar_t *core, int ret_value);
int load_robots(int argc, char **argv, corewar_t *core, int argi);
int change_int_order(int num);
int mini_printf(char const *format, ...);
int set_dump_flag(corewar_t *core, char **argv, int argi, int argc);
void print_memory(corewar_t *core);
int get_robot_number(int argc, char **argv, corewar_t *core, int argi);
int robot_fork(robot_t *robot, process_t *procs, int offset);
int set_robot_flag(robot_flg_t *flg, char **argv, int argi, int argc);
int get_robots_idx(corewar_t *core, unsigned int rid);

//functions
int func_live(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_aff(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_ld(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_add(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_sub(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_st(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_zjmp(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_xor(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_or(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_and(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_lld(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_ldi(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_lldi(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_sti(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_fork(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);
int func_lfork(UNUSED corewar_t *core, int number_args,
    type_t args[], arg_t *proc_arg);

#endif
