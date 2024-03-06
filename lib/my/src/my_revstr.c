/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** return a reversed version on the send str
*/

#include <string.h>
#include "../include/my_lib.h"

char *my_revstr(char *str)
{
    int str_len = 0;
    char swapper;
    int middle = 0;

    while (str[str_len + 1] != '\0') {
        str_len ++;
    }
    middle = str_len / 2;
    for (int i = 0; middle >= i; i ++) {
        swapper = str[i];
        str[i] = str[str_len - i];
        str[str_len - i] = swapper;
        }
    return (str);
}
