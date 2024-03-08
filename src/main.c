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

void printusage(void)
{
    my_putstr("USAGE\n./asm file_name[.s]\nDESCRIPTION\n");
    my_putstr("file_name file in assembly language to be converted");
    my_putstr(" into file_name.cor, an executable in the Virtual Machine.\n");
}

int verif_arg(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr_err("asm: wrong usage, use -h to learn more\n");
        return 1;
    }
    if (my_strncmp(argv[1], "-h", 2) == 0 && my_strlen(argv[1]) == 2) {
        printusage();
        return 2;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int fd = 0;
    int return_value = 0;

    if (verif_arg(argc, argv) == 1)
        return EXIT_ERROR;
    if (verif_arg(argc, argv) == 2)
        return EXIT_SUCCESS;
    fd = open(argv[1], O_RDWR);
    if (fd != -1) {
        if (check_file_format(argv[1]) == 0) {
            my_putstr_err("asm: wrong source file format\n");
            return EXIT_ERROR;
        }
        return_value = create_file(argv, fd);
        close(fd);
        return return_value;
    }
    my_putstr_err("asm: no sutch file or directory\n");
    return EXIT_ERROR;
}
