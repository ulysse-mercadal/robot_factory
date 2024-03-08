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

int check_file_name(char *str)
{
    int dot_nbr = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.')
            dot_nbr = i;
    }
    if (dot_nbr == -1)
        return 0;
    if (str[dot_nbr + 1] == 's' && str[dot_nbr + 2] == '\0')
        return 1;
    return 0;
}

int create_file(char *argv[], int fd)
{
    FILE *cor_file = NULL;
    char *new_file_name = NULL;

    if (check_file_name(argv[1]) == 0) {
        my_putstr_err("asm: wrong source file name or extension\n");
        return 84;
    }
    new_file_name = malloc(sizeof(char) * (my_strlen(argv[1] + 7)));
    argv[1][my_strlen(argv[1]) - 1] = '\0';
    new_file_name = my_strcat(new_file_name, "./");
    new_file_name = my_strcat(new_file_name, argv[1]);
    new_file_name = my_strcat(new_file_name, "cor");
    cor_file = fopen(new_file_name, "w+");
    write_file(fd, cor_file, argv[1]);
    fclose(cor_file);
    free(new_file_name);
    return 0;
}
