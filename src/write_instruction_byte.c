/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main of robot factory project
*/

#include "../lib/my/include/my_lib.h"
#include "../lib/rf/include/rf_lib.h"
#include "../include/rf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int get_instruction_byte_2(char *str, int i)
{
    if ((str[i] == 'z' && str[i + 1] == 'j' && str[i - 1] == '\t'))
        return 9;
    if ((str[i] == 'l' && str[i + 1] == 'd' && str[i - 1] == '\t') &&
    str[i + 2] == 'i')
        return 10;
    if (str[i] == 's' && str[i + 1] == 't' && str[i - 1] == '\t' &&
    str[i + 2] == 'i')
        return 11;
    if ((str[i] == 'f' && str[i + 1] == 'o' && str[i - 1] == '\t'))
        return 12;
    if (str[i] == 'l' && str[i + 1] == 'l' && str[i - 1] == '\t' &&
    (str[i + 3] == '\t' || str[i + 3] == ' '))
        return 13;
    if ((str[i] == 'l' && str[i + 1] == 'l' && str[i - 1] == '\t'))
        return 14;
    if ((str[i] == 'l' && str[i + 1] == 'f' && str[i - 1] == '\t'))
        return 15;
    if ((str[i] == 'a' && str[i + 1] == 'f' && str[i - 1] == '\t'))
        return 16;
    return 0;
}

int get_instruction_byte(char *str, int i)
{
    if (str[i] == 'l' && str[i + 1] == 'i' && str[i - 1] == '\t')
        return 1;
    if ((str[i] == 'l' && str[i + 1] == 'd' && str[i - 1] == '\t') &&
    (str[i + 2] == '\t' || str[i + 2] == ' '))
        return 2;
    if (str[i] == 's' && str[i + 1] == 't' && str[i - 1] == '\t' &&
    (str[i + 2] == '\t' || str[i + 2] == ' '))
        return 3;
    if (str[i] == 'a' && str[i + 1] == 'd' && str[i - 1] == '\t')
        return 4;
    if (str[i] == 's' && str[i + 1] == 'u' && str[i - 1] == '\t' &&
    str[i + 2] == 'b')
        return 5;
    if ((str[i] == 'a' && str[i + 1] == 'n' && str[i - 1] == '\t'))
        return 6;
    if ((str[i] == 'o' && str[i + 1] == 'r' && str[i - 1] == '\t'))
        return 7;
    if ((str[i] == 'x' && str[i + 1] == 'o' && str[i - 1] == '\t'))
        return 8;
    return get_instruction_byte_2(str, i);
}

int write_parameter_byte_2(char *str, int i, FILE *cor_file, int status)
{
    int result = 0;

    if (str[i] == '%' && is_a_nbr(str[i + 1]) == 1 && status == 1) {
        result = my_reverse_bytes_16(my_contextual_atoi(str, i + 1));
        fwrite(&result, 1, sizeof(uint16_t), cor_file);
    }
    if ((str[i] == ' ' || str[i] == '\t') && is_a_nbr(str[i + 1]) == 1) {
        result = my_reverse_bytes_16(my_contextual_atoi(str, i + 1));
        fwrite(&result, 1, sizeof(uint16_t), cor_file);
    }
    return status;
}

int write_parameter_byte(char *str, int i, FILE *cor_file, int status)
{
    int result = 0;

    if (str[i] == '\n')
        return 0;
    if (str[i] == 'r' && is_a_nbr(str[i + 1]) == 1) {
        result = my_contextual_atoi(str, i + 1);
        fwrite(&result, 1, sizeof(uint8_t), cor_file);
    }
    if (str[i] == '%' && str[i + 1] == ':') {
        result = my_reverse_bytes(result);
        fwrite(&result, 1, sizeof(uint16_t), cor_file);
        return 1;
    }
    if (str[i] == '%' && is_a_nbr(str[i + 1]) == 1 && status == 0) {
        result = my_reverse_bytes(my_contextual_atoi(str, i + 1));
        fwrite(&result, 1, sizeof(uint32_t), cor_file);
    }
    return write_parameter_byte_2(str, i, cor_file, status);
}
