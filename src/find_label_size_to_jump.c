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

char *get_line_before(char *str, int i)
{
    int size = 1;
    char *result = NULL;

    for (int y = i; str[y] != '\n'; y --) {
        size ++;
    }
    result = malloc(sizeof(char) * (size));
    for (int y = 0; y != size; y ++) {
        result[y] = str[i - size + 2];
        result[size] = '\0';
        i ++;
    }
    return result;
}

char *get_to_jump(char *str, int i, int size)
{
    char *result = NULL;
    char *final_str = NULL;
    char *begin = "\n\n\n";
    char *line_size = get_line_before(str, i);

    result = malloc((sizeof(char) * 20) + (sizeof(char) * size));
    for (int y = 0; y != size - 1; y++) {
        result[y] = str[i + y + 2];
        result[y + 1] = '\0';
    }
    final_str = malloc((sizeof(char) * 4) + (sizeof(char) *
    my_strlen(result)) + (sizeof(char) * my_strlen(line_size)));
    my_strcpy(final_str, begin);
    my_strcat(final_str, line_size);
    my_strcat(final_str, result);
    free(result);
    free(line_size);
    return final_str;
}

char *get_to_jump_neg(char *str, int i, int size)
{
    char *result = NULL;

    result = malloc(sizeof(char) * ((size * -1) + 4));
    result[0] = '\n';
    result[1] = '\n';
    for (int y = 2; y != ((size * - 1) - 7); y++) {
        result[y] = str[i + size + y];
        result[y + 1] = '\0';
    }
    return result;
}

int get_size_to_jump(char *str, int i, int size)
{
    char *str_to_jump = NULL;

    if (size > 0) {
        str_to_jump = get_to_jump(str, i, size);
        return get_byte_to_allocate(str_to_jump);
    }
    str_to_jump = get_to_jump_neg(str, i, size);
    return ((get_byte_to_allocate(str_to_jump) * -1));
}
