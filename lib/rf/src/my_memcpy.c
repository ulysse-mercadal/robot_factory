/*
** EPITECH PROJECT, 2024
** robot_factory lib
** File description:
** memcpy
*/

void my_memcpy(void *src, void *dest, int n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (int i = 0; i < n; i++)
        cdest[i] = csrc[i];
}
