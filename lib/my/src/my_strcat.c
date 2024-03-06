/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** jsp
*/
#include "../include/my_lib.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i]) {
        dest[len + i] = src[i];
        i ++;
    }
    dest[len + i] = '\0';
    return (dest);
}
