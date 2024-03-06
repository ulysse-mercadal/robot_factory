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

char *get_file_content(char *path, int fd)
{
    struct stat file_info;
    int file_size;
    char *result;

    path[my_strlen(path)] = '\0';
    lstat(path, &file_info);
    file_size = file_info.st_size;
    result = malloc(sizeof(char) * file_size + sizeof(char));
    while (read(fd, result, file_size));
    return result;
}

char *get_comment_field(char *str)
{
    int name_len = 0;
    char *result;
    int pos = 0;
    int nbr_back = 0;

    for (int i = 0; nbr_back != 1; i++) {
        if (str[i] == '\n')
            nbr_back ++;
        pos ++;
    }
    pos += my_strlen(".comment   ");
    for (int i = pos; str[i] != '"'; i++)
        name_len ++;
    result = malloc(sizeof(char) * (name_len + 1));
    for (int i = pos; str[i] != '"'; i++)
        result[i - pos] = str[i];
    return result;
}

char *get_name_field(char *str)
{
    int name_pos = 1;
    int name_len = 0;
    char *result;

    for (int i = 0; str[i] != '"'; i++)
        name_pos ++;
    for (int i = name_pos; str[i] != '"'; i++)
        name_len ++;
    result = malloc(sizeof(char) * (name_len + 1));
    for (int i = name_pos; str[i] != '"'; i++)
        result[i - name_pos] = str[i];
    return result;
}

void write_file(int fd, FILE *cor_file, char *path)
{
    char *file_content = get_file_content(path, fd);
    header_t *header = malloc(sizeof(header_t));

    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = my_reverse_bytes(get_byte_to_allocate(file_content));
    my_strcpy(header->prog_name, get_name_field(file_content));
    my_strcpy(header->comment, get_comment_field(file_content));
    fwrite(header, 1, sizeof(header_t), cor_file);
    write_body(file_content, cor_file);
}
