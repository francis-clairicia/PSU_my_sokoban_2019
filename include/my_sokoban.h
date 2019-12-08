/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_sokoban.h
*/

#ifndef HEADER_MY_SOKOBAN
#define HEADER_MY_SOKOBAN

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

typedef struct vector
{
    int x;
    int y;
} vector_t;

typedef struct box
{
    vector_t pos;
} box_t;

typedef struct map
{
    char const *buffer;
    char **str;
    vector_t player;
    box_t *boxes;
    int nb_boxes;
    int nb_lines;
    int *nb_columns;
    int max_nb_columns;
} map_t;

map_t *get_map(char const *buffer);
void draw_map(map_t *map);
void free_map(map_t *map);
long free_map_and_returns(map_t *map, long status);

int valid_map(map_t *map);
int valid_characters(map_t *map);
int find_player(map_t *map);
int find_boxes(map_t *map);
int find_hole(map_t *map);
int char_is_box(map_t *map, vector_t pos);

int my_sokoban(map_t *map);
void move_player(map_t *map, int *direction);
int check_game_status(map_t *map);

#endif