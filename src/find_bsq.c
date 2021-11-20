/*
** EPITECH PROJECT, 2021
** B-CPE-110-MAR-1-1-BSQ-thibaut.tran
** File description:
** find_bsq.c
*/

#include "../include/my.h"

int is_square_of_size(char **map, int row, int col, int square_size)
{
    int y = 0;
    int x = 0;
    int stock = col;
    while (y < square_size && x < square_size) {
        while (x < square_size) {
            if (map[row][col] == 'o' || map[row][col] == '\0'
            || map[row][col] == 0)
                return (0);
            x += 1;
            col += 1;
        }
        col = stock;
        x = 0;
        row += 1;
        y += 1;
    }
    return (1);
}

int check_square(char **map, int row, int col, my_struct_t my_struct)
{
    while (my_struct.k == 1) {
        my_struct.k = is_square_of_size(map, row, col, my_struct.size_sq);
        if (my_struct.k == 1)
            my_struct.size_sq += 1;
    }
    return (my_struct.size_sq);
}

int find_bsq(char **map, int nb_rows, int nb_cols, int row, int col)
{
    my_struct_t my_struct;
    my_struct.size_sq = 1;
    my_struct.k = 0;
    while (row < nb_rows) {
        while (col < nb_cols) {
            my_struct.size_sq = check_square(map, row, col, my_struct);
            if (my_struct.size_sq > my_struct.stock_size_sq) {
                my_struct.stock_size_sq = my_struct.size_sq;
                my_struct.stock_row = row;
                my_struct.stock_col = col;
            }
            col += 1;
            my_struct.k = 1;
        }
        col = 0;
        row += 1;
    }
    return ((my_struct.stock_size_sq - 1));
}

int find_col(char **map, int nb_rows, int nb_cols, int row, int col)
{
    my_struct_t my_struct;
    my_struct.size_sq = 1;
    my_struct.k = 0;
    while (row < nb_rows) {
        while (col < nb_cols) {
            my_struct.size_sq = check_square(map, row, col, my_struct);
            if (my_struct.size_sq > my_struct.stock_size_sq) {
                my_struct.stock_size_sq = my_struct.size_sq;
                my_struct.stock_row = row;
                my_struct.stock_col = col;
            }
            col += 1, my_struct.k = 1;
        }
        col = 0, row += 1;
    }
    int y = read_map_for_bug(map, nb_rows, nb_cols);
    if (y == 1)
        my_struct.stock_col = my_struct.stock_col - 1;
    return (my_struct.stock_col);
}

int find_row(char **map, int nb_rows, int nb_cols, int row, int col)
{
    my_struct_t my_struct;
    my_struct.size_sq = 1;
    my_struct.k = 0;
    while (row < nb_rows) {
        while (col < nb_cols) {
            my_struct.size_sq = check_square(map, row, col, my_struct);
            if (my_struct.size_sq > my_struct.stock_size_sq) {
                my_struct.stock_size_sq = my_struct.size_sq;
                my_struct.stock_row = row;
                my_struct.stock_col = col;
            }
            col += 1, my_struct.k = 1;
        }
        col = 0, row += 1;
    }
    return (my_struct.stock_row);
}