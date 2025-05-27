/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op
*/

#include "corewar.h"

// convert string to unsigned int
unsigned int get_uint(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++){
        nbr += (str[i] - 48);
        if (str[i + 1] != '\0')
            nbr *= 10;
    }
    return nbr;
}

// return true if unsigned integer
bool is_unumber(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

// try to read dump flag
int set_dump_flag(corewar_t *core, char **argv, int argi, int argc)
{
    if ((argi + 1) >= argc || argi >= argc)
        return 1 + ((argi + 1) >= argc);
    if (strcmp(argv[argi], "-dump") == 0){
        if (!is_unumber(argv[argi + 1]))
            return 2;
        core->flgs.dumpflg = true;
        core->flgs.dump = get_uint(argv[argi + 1]);
        return 2;
    }
    return 0;
}

// read -n flag
static int n_flag(robot_flg_t *flg, char **argv, int argi)
{
    if (argv[argi] == NULL)
        return 0;
    if (!is_unumber(argv[argi]))
        return 1;
    if (flg != NULL){
        flg->robot_number = get_uint(argv[argi]);
        flg->robot_number_bool = true;
    }
    return 1;
}

// read -a flag
static int a_flag(robot_flg_t *flg, char **argv, int argi)
{
    if (argv[argi] == NULL)
        return 0;
    if (!is_unumber(argv[argi])){
        return 1;
    }
    if (flg != NULL){
        flg->mem_offset = get_uint(argv[argi]);
        flg->mem_offset_bool = true;
    }
    return 1;
}

// set flag to default
static void set_default_flg(robot_flg_t *flg)
{
    if (flg){
        flg->mem_offset_bool = false;
        flg->robot_number_bool = false;
    }
}

// read robot flag
int set_robot_flag(robot_flg_t *flg, char **argv, int argi, int argc)
{
    int c = 0;

    set_default_flg(flg);
    if ((argi + 1) >= argc || argi >= argc)
        return 0;
    while (argv[argi + c] != NULL && argv[argi + c][0] == '-'){
        c += 1;
        if (strcmp(argv[argi + (c - 1)], "-n") == 0){
            c += n_flag(flg, argv, argi + c);
        }
        if (strcmp(argv[argi + (c - 1)], "-a") == 0){
            c += a_flag(flg, argv, argi + c);
        }
    }
    return c;
}
