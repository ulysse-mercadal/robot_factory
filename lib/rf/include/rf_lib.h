/*
** EPITECH PROJECT, 2023
** robot_factory
** File description:
** rf.h
*/


#include <stdio.h>
#include <stdint.h>

#ifndef RF_LIB
    #define RF_LIB

int my_memcpy(void *src, void *dest, int n);
uint32_t my_reverse_bytes(uint32_t bytes);
uint16_t my_reverse_bytes_16(uint16_t bytes);
int my_contextual_atoi(char const *str, int start_pos);
int is_a_nbr(char c);

#endif
