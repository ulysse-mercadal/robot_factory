/*
** EPITECH PROJECT, 2023
** robot_factory
** File description:
** robot_factory.h
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BODY_H
    #define BODY_H
    #define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */

typedef char args_type_t;

    #define T_REG 1 /* register */
    #define T_DIR 2 /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND 4 /* indirect always relative */
    #define T_LAB 8 /* LABEL */

typedef struct op_s {
    char *mnemonique;
    int nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

static op_t const op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
        "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
        "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};

#endif
