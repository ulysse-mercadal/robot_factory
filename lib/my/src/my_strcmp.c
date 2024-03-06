/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** strdup
*/

#include "../include/my_lib.h"
#include <stdlib.h>

int my_strcmp(char const *first, char *second)
{
    if (first == NULL || second == NULL)
        return 84;
    if (my_strlen(first) != my_strlen(second))
        return 84;
    for (int i = 0; first[i] != '\0'; i++) {
        if (first[i] != second[i])
            return 84;
    }
    return 0;
}
