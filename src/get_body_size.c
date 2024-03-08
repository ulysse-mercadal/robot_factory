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
#include "../include/rf.h"

int get_start_pos(char *file_content)
{
    int nbr_back = 0;
    int i = 0;

    while (nbr_back != 2) {
        if (file_content[i] == '\n')
            nbr_back ++;
        i ++;
    }
    return i;
}

int handle_indexes(char *file_content, int pos)
{
    for (int i = pos; file_content[i] != '\0'; i++) {
        if (file_content[i] == '\n')
            return IND_SIZE;
        if (file_content[i] == ',')
            return 0;
    }
    return IND_SIZE;
}

int is_a_special(char *file_content, int i)
{
    if (file_content[i + 1] == 'l' && file_content[i + 2] == 'i')
        return 1;
    if (file_content[i + 1] == 'f')
        return 1;
    return 0;
}

int get_byte_to_allocate_2(char *file_content, int i)
{
    int result = 0;

    if (file_content[i] == '\t' && file_content[i + 1] == 'z')
        result --;
    if (file_content[i] == '%' && file_content[i + 1] != ':')
        result += DIR_SIZE;
    if (file_content[i] == '%' && file_content[i + 1] == ':')
        result += handle_indexes(file_content, i);
    if (file_content[i] == 'r' && is_a_nbr(file_content[i + 1]) == 1)
        result += 1;
    if (file_content[i] == ' ' && is_a_nbr(file_content[i + 1]) == 1)
        result += 2;
    return result;
}

int get_byte_to_allocate(char *file_content)
{
    int result = 0;
    int code_start = get_start_pos(file_content) + 1;
    int tab_status = 0;

    for (int i = code_start; file_content[i] != '\0'; i ++) {
        if (file_content[i] == '\n')
            tab_status = 0;
        if (file_content[i] == '\t' && is_a_special(file_content, i) == 1 &&
        tab_status == 0) {
            result += SPECIAL_RULES_SIZE;
            tab_status ++;
        }
        if (file_content[i] == '\t' && is_a_special(file_content, i) == 0 &&
        tab_status == 0) {
            result += RULE_AND_CODING_BYTE_SIZE;
            tab_status ++;
        }
        result += get_byte_to_allocate_2(file_content, i);
    }
    return result;
}
