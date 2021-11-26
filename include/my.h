/*
** EPITECH PROJECT, 2021
** B-CPE-110-MAR-1-1-BSQ-thibaut.tran
** File description:
** my.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct struc_s {
    int stock_row;
    int stock_col;
} my_struct_t;

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
void my_putstr(char *str);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_show_word_array(char * const *tab);
char *my_strncpy (char *dest, char const *src, int n);
int read_my_file(int fd, char *buffer, int size);
int open_my_file(char const *filepath);
char *load_file_in_mem(char const *filepath);
char **load_my_tab_from_file(char const *filepath, int nb_rows, int nb_cols);
int is_square_of_size(char **map, int row, int col, int square_size);
int find_bsq(char **map, int nb_rows, int nb_cols, int row, int col);
int check_square(char **map, int row, int col, my_struct_t my_sq);
char **load_map(char **map, int size, int pos_row, int pos_col);
int find_row(char **map, int nb_rows, int nb_cols, int row, int col);
int find_col(char **map, int nb_rows, int nb_cols, int row, int col);
int read_map_filled(char **map, int nb_rows, int nb_cols);
int read_map_fix_sq_empty(char **map, int nb_rows, int nb_cols);
int read_map_fix_empty_rows(char **map, int nb_rows, int nb_cols);
int read_map_fix_empty_cols(char **map, int nb_rows, int nb_cols);
int read_map_fix_one(char **map, int nb_rows, int nb_cols);
int read_map_fix_rowline(char **map, int nb_rows, int nb_cols);
int read_map_fix_colline(char **map, int nb_rows, int nb_cols);
int read_map_nothing(char **map, int nb_rows, int nb_cols);

#endif