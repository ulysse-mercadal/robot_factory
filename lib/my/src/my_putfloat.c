/*
** EPITECH PROJECT, 2024
** lib reworked
** File description:
** print an float
*/

#include "../include/my_lib.h"

void my_putfloat(float nbr, int precision)
{
    int before_coma;
    long after_coma;

    precision = my_pow(10, precision);
    before_coma = nbr;
    after_coma = (nbr * precision) - before_coma * precision;
    if (after_coma < 0)
        after_coma *= -1;
    my_putnbr(before_coma);
    my_putchar('.');
    my_putnbr(after_coma);
    if (after_coma == 0)
        my_putchar('0');
}
