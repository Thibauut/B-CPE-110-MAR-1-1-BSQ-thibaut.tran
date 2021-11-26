/*
** EPITECH PROJECT, 2021
** B-CPE-110-MAR-1-1-BSQ-thibaut.tran
** File description:
** main.c
*/

#include "../include/my.h"

int read_map_fix_rowline(char **map, int nb_rows, int nb_cols)
{
    if ((nb_rows - 1) == 1 && nb_cols > 1) {
        if (map[0][0] == '.')
            map[0][0] = 'x';
        my_show_word_array(map);
        return (1);
    }
    return (0);
}

int read_map_fix_colline(char **map, int nb_rows, int nb_cols)
{
    if ((nb_rows - 1) > 1 && nb_cols == 1) {
        if (map[0][0] == '.')
            map[0][0] = 'x';
        my_show_word_array(map);
        return (1);
    }
    return (0);
}

int nb_cols(char **av)
{
    int i = 0;
    int nb_cols = 0;
    char *tab_str = load_file_in_mem(av[1]);
    while (tab_str[i] != '\n')
        i += 1;
    i += 1;
    while (tab_str[i + nb_cols] != '\n')
        nb_cols += 1;
    return (nb_cols);
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

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (open_my_file(av[1]) == 84)
        return (84);
    int rows = my_getnbr(load_file_in_mem(av[1])) + 1, cols = nb_cols(av);
    int row = 0, col = 0;
    char **tab = load_my_tab_from_file(av[1], rows, cols);
    if (read_map_fix_rowline(tab, rows, cols) == 1 ||
    read_map_fix_colline(tab, rows, cols) == 1 || read_map_filled(tab, rows, cols) == 1)
        return (0);
    int i = find_bsq(tab, rows, cols, row, col);
    int pos_row = find_row(tab, rows, cols, row, col);
    int pos_col = find_col(tab, rows, cols, row, col);
    if (read_map_fix_one(tab, rows, cols) == 1)
        pos_col += 1;
    if (read_map_fix_rowline(tab, rows, cols) == 1)
        pos_col += 1, pos_row += 1;
    char **map = load_map(tab, i, pos_row, pos_col);
    my_show_word_array(map);
}