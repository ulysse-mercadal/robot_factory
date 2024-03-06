/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** my version of atoi
*/

#include "../include/my_lib.h"
#include <unistd.h>
#include <limits.h>

int my_atoi(char const *str)
{
    long result = 0;
    int i = 0;
    int negatif_factor = 1;

    while ((str[i] == '-') || (str[i] == '+')) {
        if (str[i] == '-')
        negatif_factor *= -1;
        i ++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result *= 10;
        result += str[i] - '0';
        i ++;
    }
    if ((result > INT_MAX) || (result < INT_MIN))
        return (0);
    return (result * negatif_factor);
}
