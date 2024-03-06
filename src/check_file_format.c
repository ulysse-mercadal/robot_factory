/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main of robot factory project
*/

#include "../include/rf.h"
#include "../lib/my/include/my_lib.h"
#include "../lib/rf/include/rf_lib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int len_word(char **str)
{
    int len = 0;

    for (unsigned i = 0; str[i] != NULL; i++)
        len++;
    return len;
}

static char *replace_tab(char *str)
{
    for (unsigned i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return str;
}

int verif_header(char **file_line)
{
    char **first_line = my_split(file_line[0], ' ');
    char **second_line = my_split(file_line[1], ' ');

    if (len_word(first_line) <= 1 ||
        my_strcmp(first_line[0], NAME_CMD_STRING) == 84)
        return 1;
    if (len_word(second_line) <= 1 ||
        my_strcmp(second_line[0], COMMENT_CMD_STRING) == 84)
        return 1;
    for (int i = 0; first_line[i] != NULL; i++)
        free(first_line[i]);
    for (int i = 0; second_line[i] != NULL; i++)
        free(second_line[i]);
    free(first_line);
    free(second_line);
    return 0;
}

static char **stock_label(char **line, char **label)
{
    char **line_split = NULL;
    unsigned index = 0;

    for (unsigned int i = 2; line[i] != NULL; i++) {
        line_split = my_split(line[i], ' ');
        if (line_split[0][my_strlen(line_split[0]) - 1] == ':') {
            label[index] = malloc(sizeof(char) * my_strlen(line_split[0]));
            label[index] = my_strncat(label[index], line_split[0],
            my_strlen(line_split[0]) - 1);
            index ++;
        }
        for (int i = 0; line_split[i] != NULL; i++)
            free(line_split[i]);
        free(line_split);
    }
    label[index] = NULL;
    return label;
}

char **recup_label(char **line)
{
    unsigned int nb_malloc = 0;
    char **line_split = NULL;
    char **label = NULL;

    for (unsigned int i = 2; line[i] != NULL; i++) {
        line_split = my_str_split(line[i], " ");
        if (line_split[0][my_strlen(line_split[0]) - 1] == ':')
            nb_malloc ++;
        for (int i = 0; line_split[i] != NULL; i++)
            free(line_split[i]);
        free(line_split);
    }
    label = malloc(sizeof(char *) * (nb_malloc) + 1);
    label = stock_label(line, label);
    return label;
}

int verif_body(char **line)
{
    char **label = recup_label(line);

    for (unsigned int i = 2; line[i] != NULL; i++) {
        if (verif_line_body(line[i], label) == 1)
        return 1;
    }
    for (int i = 0; label[i] != NULL; i++)
        free(label[i]);
    return 0;
}

int check_file_format(char *path)
{
    char *file_content = my_get_file(path);
    char **file_line = my_split((file_content), '\n');

    if (len_word(file_line) == 1)
        return 0;
    if (verif_header(file_line) == 1)
        return 0;
    if (verif_body(file_line) == 1)
        return 0;
    for (int i = 0; file_line[i] != NULL; i++)
        free(file_line[i]);
    free(file_content);
    free(file_line);
    return 1;
}
