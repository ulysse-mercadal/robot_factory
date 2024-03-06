/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** copy a str
*/

#include "../include/my_lib.h"

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0'; i ++) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }
    return dest;
}
