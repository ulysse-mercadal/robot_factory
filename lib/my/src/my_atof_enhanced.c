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

int check_if_is_too_long(char const *str, int i, int precision)
{
    while (str[i] != '\0')
        i ++;
    if (i >= precision)
        return precision;
    return i;
}

double get_after_comma_2(char const *str, int i, int precision)
{
    double result = 0;

    precision = check_if_is_too_long(str, i, precision);
    if ((str[i] != '\0') && (precision <= 6)) {
        for (int i2 = precision; i2 != 0; i2 --) {
            result += str[i + i2 - 1] - '0';
            result /= 10;
        }
        return (result);
    }
    return (result);
}

double my_atof_enhanced(char const *str, int precision)
{
    int i = 0;
    double result = (double) my_atoi(str);

    while ((str[i] != '\0') && (str[i - 1] != '.'))
        i ++;
    if (result >= 0)
        result += get_after_comma_2(str, i, precision);
    else
        result -= get_after_comma_2(str, i, precision);
    return (result);
}
