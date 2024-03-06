/*
** EPITECH PROJECT, 2024
** clean str
** File description:
** function to remove waste space
*/
#include "../include/my_lib.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


char *my_get_file(char *path)
{
    int file = open(path, O_RDONLY);
    struct stat file_info;
    int file_size = 0;
    char *result = NULL;

    path[my_strlen(path)] = '\0';
    lstat(path, &file_info);
    file_size = file_info.st_size;
    result = malloc(sizeof(char) * file_size + 1);
    while (read(file, result, file_size));
    close(file);
    return result;
}
