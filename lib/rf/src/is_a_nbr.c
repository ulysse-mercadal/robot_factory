/*
** EPITECH PROJECT, 2024
** robot_factory lib
** File description:
** is a nbr ?
*/

int is_a_nbr(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}
