/*
** EPITECH PROJECT, 2023
** robot_factory
** File description:
** robot_factory.h
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef RF
    #define RF

// ! ||---------------------------------------------------------------------||
// ! ||                          utility macros                             ||
// ! ||---------------------------------------------------------------------||

    #define EXIT_ERROR 84
    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512 /* modulo of the index < */
    #define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

// ! ||---------------------------------------------------------------------||
// ! ||                           size macros                               ||
// ! ||---------------------------------------------------------------------||

    #define RULE_AND_CODING_BYTE_SIZE 2
    #define SPECIAL_RULES_SIZE 1
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REPERTORY_SIZE 1
    #define REG_SIZE DIR_SIZE

// ! ||---------------------------------------------------------------------||
// ! ||                header struct to fill and fwrite                     ||
// ! ||---------------------------------------------------------------------||

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 4085508608

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

// ! ||---------------------------------------------------------------------||
// ! ||                   list of projetc functions                         ||
// ! ||---------------------------------------------------------------------||

int create_file(char *argv[], int fd);
int check_file_format(char *path);
int get_byte_to_allocate(char *file_content);
int get_instruction_byte(char *str, int i);
int get_start_pos(char *file_content);
int write_parameter_byte(char *str, int i, FILE *cor_file, int status);
int get_start_pos(char *file_content);
int verif_line_body(char *line);
int get_label(char *str, int i);
int get_size_to_jump(char *str, int i, int size);
void write_body(char *file_content, FILE *cor_file);
void write_coding_byte(char *str, int i, FILE *cor_file);
void write_file(int fd, FILE *cor_file, char *path);
char *get_file_content(char *path, int fd);

#endif
