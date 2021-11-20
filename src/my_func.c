/*
** EPITECH PROJECT, 2021
** B-CPE-110-MAR-1-1-BSQ-thibaut.tran
** File description:
** my_func.c
*/

#include "../include/my.h"

void my_putstr(char *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i]; i += 1)
        write(1, &str[i], 1);
}

char *my_strncpy (char *dest, char const *src, int n)
{
    int a = 0;
    while (a != n) {
        dest[a] = src[a];
        a = a + 1;
    }
    if (n > a)
        dest[a] = '\0';
    return (dest);
}

int my_show_word_array(char *const *tab)
{
    int a = 0;
    while (tab[a] != 0) {
        my_putstr(tab[a]);
        a++;
    }
    return (0);
}