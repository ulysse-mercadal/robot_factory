/*
** EPITECH PROJECT, 2024
** robot_factory lib
** File description:
** atoi from a pos given
*/

#include <unistd.h>
#include <limits.h>

int my_contextual_atoi(char const *str, int start_pos)
{
    long result = 0;
    int i = start_pos;
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
