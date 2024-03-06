/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** print a full string
*/

#include "../include/my_lib.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i ++) {
        my_putchar(str[i]);
    }
}
