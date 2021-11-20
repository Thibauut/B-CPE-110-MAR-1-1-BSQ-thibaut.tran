/*
** EPITECH PROJECT, 2021
** B-CPE-110-MAR-1-1-BSQ-thibaut.tran
** File description:
** main.c
*/

#include "../include/my.h"

int nb_rows(char const *filepath)
{
    int size_y = 1;
    int i = 0;
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open(filepath, O_RDONLY);
    read(fd, buffer, size);
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            size_y += 1;
        i += 1;
    }
    return (size_y);
    close(fd);
}

int nb_cols(char const *filepath)
{
    int size_y = 1;
    int i = 0;
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open(filepath, O_RDONLY);
    read(fd, buffer, size);
    while (buffer[i] != '\n') {
        size_y += 1;
        i += 1;
    }
    return (size_y);
    close(fd);
}

char **load_map(char **map, int size, int pos_row, int pos_col)
{
    int row = size + pos_row;
    int col = size + pos_col;
    int stock = pos_col;
    while (pos_row < row) {
        while (pos_col < col) {
            if (map[pos_row][pos_col] == '.')
                map[pos_row][pos_col] = 'x';
            pos_col += 1;
        }
        pos_col = stock;
        pos_row += 1;
    }
    return (map);
}

int read_map_for_bug(char **map, int nb_rows, int nb_cols)
{
    int y = 0;
    int x = 0;
    while (y < nb_rows) {
        while (x < nb_cols) {
            if (map[y][x] == 'o')
                return (0);
            x += 1;
        }
        x = 0;
        y += 1;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (open_my_file(av[1]) == 84)
        return (84);
    int rows = nb_rows(av[1]);
    int cols = nb_cols(av[1]);
    int row = 0;
    int col = 0;
    char **tab = load_my_tab_from_file(av[1], rows, cols);
    int i = find_bsq(tab, rows, cols, row, col);
    int pos_col = find_col(tab, rows, cols, row, col);
    int pos_row = find_row(tab, rows, cols, row, col);
    char **map = load_map(tab, i, pos_row, pos_col);
    my_show_word_array(map);
}