/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** a better version of my_atoi
*/

#include "../include/my_lib.h"
#include <unistd.h>
#include <limits.h>

int my_atoi_enhanced(char const *str, int nbr)
{
    long result = 0;
    int i = 0;
    int negatif_factor = 1;

    while ((str[i] == '-') || (str[i] == '+')) {
        if (str[i] == '-')
        negatif_factor *= -1;
        i ++;
    }
    for (int y = i; y != nbr + i; y ++){
        if (str[y] >= '0' && str[y] <= '9') {
            result *= 10;
            result += str[y] - '0';
        }
    }
    if ((result > INT_MAX) || (result < INT_MIN))
        return (0);
    return (result * negatif_factor);
}
