/*
** EPITECH PROJECT, 2024
** lib rf
** File description:
** revers binary of an int
*/

#include <stdio.h>
#include <stdint.h>

uint16_t my_reverse_bytes_16(uint16_t bytes)
{
    uint16_t aux = 0;
    uint8_t byte;

    for (int i = 0; i < 16; i += 8) {
        byte = (bytes >> i) & 255;
        aux |= byte << (8 - i);
    }
    return aux;
}
