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
    return (84);
}