/*
** EPITECH PROJECT, 2021
** B-CPE-110-MAR-1-1-BSQ-thibaut.tran
** File description:
** load_my_tab.c
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    return i;
}

int open_my_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (84);
    return (fd);
}

void read_my_file(int fd, char *buffer, int size)
{
    read(fd, buffer, size);
    return;
}

char *load_file_in_mem(char const *filepath)
{
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open_my_file(filepath);
    read_my_file(fd, buffer, size);
    return (buffer);
    close(fd);
}

char **load_my_tab_from_file(char const *filepath, int nb_rows, int nb_cols)
{
    int i = 0, j = 0, k = 0;
    char *tab_str = load_file_in_mem(filepath);
    struct stat buf;
    stat(filepath, &buf);
    int size_tab = buf.st_size;
    char **tab = malloc(sizeof(char *) * size_tab);
    while (tab_str[k] != '\n')
        k += 1;
    k += 1;
    while (i < nb_rows) {
        tab[i] = malloc(sizeof(char *) * nb_cols);
        while (j < nb_cols) {
            tab[i][j] = tab_str[k];
            j += 1, k += 1;
        }
        j = 0, k += 1, i += 1;
    }
    return (tab);
}