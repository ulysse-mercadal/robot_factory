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

int find_label_pos(char *str, int i, char *label)
{
    for (int y = 0; y != my_strlen(label); y ++) {
        if (str[i + y] != label[y]) {
            return 1;
        }
    }
    return 0;
}

char *get_word(char *str, int i)
{
    int len = get_world_len(str, " ,\t\n\0", i + 2);
    char *result = NULL;

    result = malloc(sizeof(char) * (len + 1));
    for (int y = 0; y != len; y++) {
        result[y] = str[i + 2];
        result[y + 1] = '\0';
        i++;
    }
    return result;
}

int get_label_2(char *str, int i, char *label)
{
    int pos = 0;

    while (find_label_pos(str, i, label) == 1) {
        pos --;
        i --;
    }
    return pos;
}

int get_label(char *str, int i)
{
    char *lab = get_word(str, i);
    char *label = NULL;
    int pos = 0;
    int i2 = i;

    i += 3;
    label = malloc(sizeof(char) * (my_strlen(lab) + 2));
    my_strcat(label, "\n");
    my_strcat(label, lab);
    while (find_label_pos(str, i, label) == 1) {
        if (str[i] == '\0') {
            return get_label_2(str, i2, label);
        }
        pos ++;
        i++;
    }
    return pos;
}

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
