/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** find a str in a str
*/

#include "../include/my_lib.h"

int check_rest(char *str, int i, char const *to_find)
{
    for (int y = 0; to_find[y] != '\0'; y ++) {
        if (str[i + y] != to_find[y])
            return 0;
    }
    return 1;
}

int my_strstr(char *source_string, char const *string_to_find)
{
    int result = 0;

    if (string_to_find[0] == '\0')
        return (0);
    for (int i = 0; source_string[i] != '\0'; i ++) {
        if ((source_string[i] == string_to_find[0]) &&
        (check_rest(source_string, i, string_to_find) == 1)) {
            result ++;
        }
    }
    return result;
}
