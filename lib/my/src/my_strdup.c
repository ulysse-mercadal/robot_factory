/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** my version of atof
*/

#include "../include/my_lib.h"
#include <stdlib.h>

char *my_strdup(char const *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(result, str);
    return result;
}
