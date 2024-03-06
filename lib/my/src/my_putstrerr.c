/*
** EPITECH PROJECT, 2023
** solostumper 03
** File description:
** modulo show time !
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putstr_err(char const *str)
{
    for (int i = 0; str[i] != '\0'; i ++) {
        write(2, &str[i], 1);
    }
}
