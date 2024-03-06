/*
** EPITECH PROJECT, 2024
** clean str
** File description:
** function to remove waste space
*/
#include "../include/my_lib.h"
#include <stdlib.h>

char *my_cleanstr(char *str, char letter)
{
    int len = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (len));
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((i == 0 && str[i] != letter) ||
        (i > 0 && str[i - 1] == letter && str[i] != letter) ||
        (i > 0 && str[i - 1] != letter && str[i] == letter) ||
        (i != (len - 1) && str[i] != letter)) {
            new_str[index] = str[i];
            new_str[index + 1] = '\0';
            index ++;
        }
    }
    while (index != len) {
        new_str[index] = '\0';
        index ++;
    }
    return new_str;
}
