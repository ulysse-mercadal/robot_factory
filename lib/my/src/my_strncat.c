/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** a
*/
#include "../include/my_lib.h"
#include <stddef.h>

char *my_strncat(char *dest, char const *src, int len)
{
    int len1 = my_strlen(dest);

    for (int i = 0; i < len; i++) {
        dest[len1 + i] = src[i];
    }
    dest[my_strlen(dest)] = '\0';
    return dest;
}
