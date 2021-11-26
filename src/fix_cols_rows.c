/*
** EPITECH PROJECT, 2021
** B-CPE-110-MAR-1-1-BSQ-thibaut.tran
** File description:
** check_error.c
*/

#include "../include/my.h"

int read_map_filled(char **map, int nb_rows, int nb_cols)
{
    int y = 0;
    int x = 0;
    while (y < nb_rows) {
        while (x < nb_cols) {
            if (map[y][x] == '.')
                return (0);
            x += 1;
        }
        x = 0;
        y += 1;
    }
    my_show_word_array(map);
    return (1);
}

int read_map_fix_sq_empty(char **map, int nb_rows, int nb_cols)
{
    int y = 0;
    int x = 0;
    if ((nb_rows - 1) == nb_cols) {
        while (y < nb_rows) {
            while (x < nb_cols) {
                if (map[y][x] == 'o')
                    return (1);
                else
                    return (2);
                x += 1;
            }
            x = 0;
            y += 1;
        }
    }
    return (0);
}

int read_map_fix_empty_rows(char **map, int nb_rows, int nb_cols)
{
    int y = 0;
    int x = 0;
    if (nb_rows > nb_cols) {
        while (y < nb_rows) {
            while (x < nb_cols) {
                if (map[y][x] == 'o')
                    return (1);
                x += 1;
            }
            x = 0;
            y += 1;
        }
    }
    return (0);
}

int read_map_fix_empty_cols(char **map, int nb_rows, int nb_cols)
{
    int y = 0;
    int x = 0;
    if (nb_rows < nb_cols) {
        while (y < nb_rows) {
            while (x < nb_cols) {
                if (map[y][x] == 'o')
                    return (1);
                x += 1;
            }
            x = 0;
            y += 1;
        }
    }
    return (0);
}

int read_map_fix_one(char **map, int nb_rows, int nb_cols)
{
    int y = 0;
    int x = 0;
    if ((nb_rows - 1) == 1 && nb_cols == 1) {
        while (y < nb_rows) {
            while (x < nb_cols) {
                if (map[y][x] != 'o')
                    return (1);
                x += 1;
            }
            x = 0;
            y += 1;
        }
    }
    return (0);
}