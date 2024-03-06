/*
** EPITECH PROJECT, 2024
** lib_reworked
** File description:
** my version of pow
*/

#include <limits.h>

int my_pow(int nb, int pow)
{
    int i = 0;
    long int result = 1;

    if (pow < 0)
        return (0);
    if (pow == 0)
        return (1);
    while (i < pow) {
        result *= nb;
        i ++;
    }
    return (result % INT_MAX);
}
