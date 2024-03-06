/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** compare n char of a string
*/

#include "../include/my_lib.h"
int my_strncmp(char const *str1, char const *str2, int n)
{
    int i = 0;

    while (i != n) {
        if ((str1[i] != str2[i]) || (str2[i] == '\0'))
            return (str1[i] - str2[i]);
        i ++;
    }
    return (0);
}
