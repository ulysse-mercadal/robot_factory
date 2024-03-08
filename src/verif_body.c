/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main of robot factory project
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/my/include/my_lib.h"
#include "../lib/rf/include/rf_lib.h"
#include "../include/body.h"

int verif_param(char **parameter)
{
    return 0;
}

int verify_instruct(char *instruction)
{
    char *instruct = NULL;

    if (instruction == NULL)
        return 0;
    instruct = my_strdup(instruction);
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, instruct) == 0)
            return 0;
    }
    free(instruct);
    return 1;
}

int verif_line_body(char *line)
{
    char **instruction = my_split(line, ' ');
    int result = 0;

    if (instruction[1] == NULL && line[my_strlen(line) - 1] == ':')
        return 0;
    if (instruction[0][my_strlen(instruction[0]) - 1] == ':') {
        if (verify_instruct(instruction[1]) == 1)
            return 1;
        result = verif_param(instruction);
    } else {
        if (verify_instruct(instruction[0]) == 1)
            return 1;
        result = verif_param(instruction);
    }
    for (int i = 0; instruction[i] != NULL; i++)
        free(instruction[i]);
    free(instruction);
    return result;
}
