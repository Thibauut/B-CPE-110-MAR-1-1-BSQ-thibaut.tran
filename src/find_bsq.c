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
            if (map[row][col] != '.')
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

int find_bsq(char **map, int nb_rows, int nb_cols, int row, int col)
{
    int size_sq = 0, stock_size_sq = 0, k = 0;
    while (row < nb_rows) {
        while (col < nb_cols) {
            while (k == 1) {
                k = is_square_of_size(map, row, col, size_sq);
                if (k == 1)
                    size_sq += 1;
            }
            if (size_sq > stock_size_sq)
                stock_size_sq = size_sq;
            col += 1, k = 1;
        }
        col = 0, row += 1;
    }
    if (read_map_fix_empty(map, nb_rows, nb_cols) == 1)
        stock_size_sq = stock_size_sq + 1;
    return (stock_size_sq - 1);
}

int find_col(char **map, int nb_rows, int nb_cols, int row, int col)
{
    int size_sq = 0, stock_size_sq = 0, k = 0, stock_col = 0;
    while (row < nb_rows) {
        while (col < nb_cols) {
            while (k == 1) {
                k = is_square_of_size(map, row, col, size_sq);
                if (k == 1)
                    size_sq += 1;
            }
            if (size_sq > stock_size_sq) {
                stock_size_sq = size_sq;
                stock_col = col;
            }
            col += 1, k = 1;
        }
        col = 0, row += 1;
    }
    if (read_map_fix_col(map, nb_rows, nb_cols) == 1)
        stock_col = stock_col - 1;
    if (read_map_fix_empty2(map, nb_rows, nb_cols) == 1)
        stock_col = stock_col + 1;
    return (stock_col);
}

int find_row(char **map, int nb_rows, int nb_cols, int row, int col)
{
    int size_sq = 0, stock_size_sq = 0, k = 0;
    int stock_row = 0;
    while (row < nb_rows) {
        while (col < nb_cols) {
            while (k == 1) {
                k = is_square_of_size(map, row, col, size_sq);
                if (k == 1)
                    size_sq += 1;
            }
            if (size_sq > stock_size_sq) {
                stock_size_sq = size_sq;
                stock_row = row;
            }
            col += 1, k = 1;
        }
        col = 0, row += 1;
    }
    if (read_map_fix_empty2(map, nb_rows, nb_cols) == 1)
        stock_row = stock_row - 1;
    return (stock_row);
}