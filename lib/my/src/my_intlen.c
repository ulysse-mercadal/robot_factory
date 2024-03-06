/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** my_intlen
*/

#include "../include/my_lib.h"

int my_intlen(int nbr)
{
    int i = 0;

    while (nbr > my_pow(10, i)) {
        i ++;
    }
    return i;
}
