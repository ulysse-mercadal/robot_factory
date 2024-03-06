/*
** EPITECH PROJECT, 2023
** bootstrap phoenix
** File description:
** phoenixlib.h
*/

#ifndef LIBRARY
    #define LIBRARY

void my_putchar(char c);
void my_putnbr(int nbr);
void my_putfloat(float nbr, int precision);
void my_putstr(char const *str);
void my_putstr_err(char const *str);
int my_atoi(char const *str);
int my_atoi_enhanced(char const *str, int nbr);
int my_strlen(char const *str);
int my_intlen(int nbr);
int get_word_len(char *str, char *separator);
int get_world_len(char *str, char *separator, int i);
int get_nbr_world(char *str, char *separator);
int my_strncmp(char const *str1, char const *str2, int n);
int my_strstr(char *source_string, char const *string_to_find);
int my_pow(int nbr, int pow);
int my_strcmp(char const *first, char *second);
double my_atof(char const *str);
double my_atof_enhanced(char const *str, int precision);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_get_file(char *path);
char *my_strdup(char const *str);
char *my_strncat(char *dest, char const *src, int len);
char *my_cleanstr(char *str, char letter);
char *my_strcat(char *dest, char const *src);
char **my_split(char *str, char sep);
char **my_str_split(char *str, char *separators);
#endif
