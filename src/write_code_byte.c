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

int get_coding_byte_2(char *str, int i, int result)
{
    if (str[i] == 'r' && is_a_nbr(str[i + 1]) == 1) {
        result <<= 2;
        result |= 1;
    }
    if (str[i] == '%') {
        result <<= 2;
        result |= 2;
    }
    if ((str[i] == ' ' || str[i] == '\t') && is_a_nbr(str[i + 1]) == 1) {
        result <<= 2;
        result |= 3;
    }
    return result;
}

int get_coding_byte(char *str, int i)
{
    int result = 0;
    int result2 = 0;
    int status = 0;

    while (str[i] != '\n' || str[i] == '\0') {
        result2 = get_coding_byte_2(str, i, result);
        if (result2 != result) {
            status ++;
            result = result2;
        }
        i ++;
    }
    while (status != 4) {
        result <<= 2;
        (status) ++;
    }
    return result;
}

void write_coding_byte(char *str, int i, FILE *cor_file)
{
    int coding_byte;

    if (str[i] == 'l' && str[i + 1] == 'i' && str[i - 1] == '\t')
        return;
    if (str[i] == 'z' && str[i - 1] == '\t')
        return;
    if (str[i] == 'f' && str[i + 1] == 'o' && str[i - 1] == '\t')
        return;
    coding_byte = get_coding_byte(str, i);
    fwrite(&coding_byte, 1, sizeof(uint8_t), cor_file);
}
