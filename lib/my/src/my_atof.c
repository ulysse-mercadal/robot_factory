/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** my version of atof
*/

#include "../include/my_lib.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>


double get_after_comma(char const *str, int i)
{
    int i2 = i;
    int after_coma_lenght = 0;
    double result = 0;

    if (str[i2] != '\0') {
        while (str[i2] >= '0' && str[i2] <= '9') {
            after_coma_lenght ++;
            i2 ++;
        }
    } else
        return 0;
    if ((str[i] != '\0') && (after_coma_lenght <= 6)) {
        for (int i3 = after_coma_lenght; i3 != 0; i3 --) {
            result += str[i + i3 - 1] - '0';
            result /= 10;
        }
        return (result);
    }
    return (result);
}

double my_atof(char const *str)
{
    int i = 0;
    double result = (double) my_atoi(str);

    while ((str[i] != '\0') && (str[i - 1] != '.'))
        i ++;
    if (result >= 0)
        result += get_after_comma(str, i);
    else
        result -= get_after_comma(str, i);
    return (result);
}
