/*
** EPITECH PROJECT, 2024
** lib reworked
** File description:
** print an int
*/

#include "../include/my_lib.h"
#include <unistd.h>
#include <limits.h>
void my_putnbr(int nbr)
{
    if (nbr == INT_MIN) {
        write(1, "-2147483648", 12);
        return;
    }
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr >= 10) {
        my_putnbr(nbr / 10);
    }
    my_putchar(nbr % 10 + '0');
    return;
}
