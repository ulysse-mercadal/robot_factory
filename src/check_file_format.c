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

static char *replace_tab(char *str)
{
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return str;
}

int verif_header(char **str)
{
    char *first_line = my_strdup(str[0]);
    char *second_line = my_strdup(str[1]);

    first_line[6] = '\0';
    second_line[9] = '\0';
    if ((my_strstr(first_line, ".name") == 0) || (str[0][0] != ' ' &&
    str[0][0] != '\t') || (str[0][7] != '"') ||
    (str[0][my_strlen(str[0]) - 1] != '"')) {
        my_putstr_err("asm: error in the .name field\n");
        return 1;
    }
    if ((my_strstr(second_line, ".comment") == 0) || (str[1][0] != ' ' &&
    str[1][0] != '\t') || (str[1][10] != '"') ||
    (str[1][my_strlen(str[1]) - 1] != '"')) {
        my_putstr_err("asm: error in the .comment field\n");
        return 1;
    }
    return 0;
}

static int verif_line(char *line)
{
    int letter = 0;

    for (unsigned i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t' &&
            line[i] != '\n' && line[i] != '\0')
            letter++;
    }
    return letter;
}

int verif_body(char **line)
{
    for (unsigned int i = 2; line[i] != NULL; i++) {
        if (line[i][0] == '\0' && line[i + 1] != NULL) {
            continue;
        }
        if (verif_line(line[i]) == 0)
            return 1;
        else
            continue;
        if (line[i + 1] == NULL)
            return 0;
        if (verif_line_body(replace_tab(line[i])) == 1) {
            my_putstr_err("asm: error at the line ");
            my_putnbr(i + 1);
            my_putstr_err("\n");
            return 1;
        }
    }
    return 0;
}

int check_file_format(char *path)
{
    char *file_content = my_get_file(path);
    char **file_line = my_split((file_content), '\n');

    if (verif_header(file_line) == 1) {
        my_putstr_err("asm: wrong header format! go check your file :/\n");
        return 0;
    }
    if (verif_body(file_line) == 1) {
        my_putstr_err("asm: wrong body format! go check your file :/\n");
        return 0;
    }
    free(file_content);
    free(file_line);
    return 1;
}
