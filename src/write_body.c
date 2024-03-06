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

void write_body(char *file_content, FILE *cor_file)
{
    int code_start = get_start_pos(file_content) + 1;
    int indirect_status = 0;
    int instruction_byte = 0;

    for (int i = code_start; file_content[i] != '\0'; i++) {
        instruction_byte = get_instruction_byte(file_content, i);
        indirect_status = write_parameter_byte(file_content, i, cor_file,
        indirect_status);
        if (instruction_byte != 0) {
            fwrite(&instruction_byte, 1, sizeof(uint8_t), cor_file);
            write_coding_byte(file_content, i, cor_file);
        }
    }
}
