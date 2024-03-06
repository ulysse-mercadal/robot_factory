/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** better str_to_world_array
*/

#include "../include/my_lib.h"
#include <stdlib.h>
#include <stdio.h>

int is_a_separator(char letter, char *separator)
{
    for (int i = 0; separator[i] != '\0'; i++) {
        if (separator[i] == letter) {
            return 1;
        }
    }
    return 0;
}

int get_word_len(char *str, char *separator)
{
    int i = 0;
    int result = 0;

    while ((is_a_separator(str[i], separator) == 1) &&
    (str[i] != '\0'))
        i++;
    while (is_a_separator(str[i], separator) == 0){
        i++;
        result ++;
        if (str[i] == '\0')
            return (result);
    }
    return (result);
}

int get_nbr_world(char *str, char *separator)
{
    int result = 0;

    if (is_a_separator(str[0], separator) == 1)
        result = 1;
    for (int i = 1; str[i] != '\0'; i ++) {
        if ((is_a_separator(str[i - 1], separator) == 0) &&
        (is_a_separator(str[i], separator) == 1))
            result ++;
    }
    return (result);
}

int get_world_len(char *str, char *separator, int i)
{
    int result = 0;

    while (is_a_separator(str[i], separator) == 0) {
        result ++;
        i ++;
    }
    return (result);
}

char **my_str_split(char *str, char *spaces)
{
    char **result = malloc(sizeof(char *) * (get_nbr_world(str, spaces) + 2));
    int y = 0;
    int w = 0;

    result[0] = malloc(sizeof(char) * (get_word_len(str, spaces) + 5));
    for (int i = 0; str[i] != '\0'; i ++) {
        if ((is_a_separator(str[i], spaces) == 1)) {
            y++;
            result[y] = malloc(sizeof(char) *
            (get_world_len(str, spaces, i + 2) + 5));
            w = 0;
            result[y + 1] = malloc(sizeof(void *));
            result[y + 1] = NULL;
        } else {
        result[y][w] = str[i];
        result[y][w + 1] = '\0';
        w ++;
        }
    }
    return result;
}
