/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** get the lenght of a str
*/

#include "../include/my_lib.h"

int my_strlen(char const *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        result ++;
    }
    return result;
}
