/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** find_hole.c
*/

#include "my_sokoban.h"

int find_hole(map_t *map)
{
    int count = 0;
    int x = 0;
    int y = 0;

    while (y < map->nb_lines) {
        if (map->str[y][x] == 'O')
            count += 1;
        x += 1;
        if (x == map->nb_columns[y]) {
            x = 0;
            y += 1;
        }
    }
    if (count == 0)
        return (0);
    return (count == map->nb_boxes);
}