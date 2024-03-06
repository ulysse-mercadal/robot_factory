/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** print one char
*/

#include "../include/my_lib.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
