/*
** EPITECH PROJECT, 2024
** lib rf
** File description:
** revers binary of an int
*/

#include <stdio.h>
#include <stdint.h>

uint32_t my_reverse_bytes(uint32_t bytes)
{
    uint32_t aux = 0;
    uint8_t byte;

    for (int i = 0; i < 32; i += 8) {
        byte = (bytes >> i) & 255;
        aux |= byte << (24 - i);
    }
    return aux;
}
