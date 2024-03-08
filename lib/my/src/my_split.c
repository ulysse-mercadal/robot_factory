/*
** EPITECH PROJECT, 2023
** my_str_to_world_array
** File description:
** transform str to world array
*/
#include "../include/my_lib.h"
#include <stdlib.h>

int nb_word(char *str, char sep)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep)
            nb++;
    }
    nb += 2;
    return nb;
}

void malloc_word(char **dest, char *str, char sep)
{
    int letter = 0;
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        letter ++;
        if (str[i] == sep) {
            dest[word] = malloc(sizeof(char) * (letter + 1));
            word++;
            letter = 0;
        }
    }
    dest[word] = malloc(sizeof(char) * (letter + 1));
    dest[word + 1] = NULL;
}

void fill_word(char **dest, char *str, char sep)
{
    int letter = 0;
    int word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            dest[word][letter] = '\0';
            word++;
            letter = 0;
            continue;
        }
        dest[word][letter] = str[i];
        letter++;
    }
    if (dest[word][letter - 1] == '\n')
        dest[word][letter - 1] = '\0';
    dest[word][letter] = '\0';
    dest[word + 1] = NULL;
}

char **my_split(char *str, char sep)
{
    char *str_off = my_cleanstr(str, ' ');
    char **dest = malloc(sizeof(char *) * nb_word(str_off, sep));

    malloc_word(dest, str_off, sep);
    fill_word(dest, str_off, sep);
    free(str_off);
    return dest;
}
