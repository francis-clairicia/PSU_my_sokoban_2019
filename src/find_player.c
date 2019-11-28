/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** find_player.c
*/

#include "my_sokoban.h"

int find_player(map_t *map)
{
    int x = 0;
    int y = 0;

    while (y < map->nb_lines) {
        x = my_find_char(map->str[y], 'P');
        if (x >= 0) {
            map->player.x = x;
            map->player.y = y;
            map->str[y][x] = ' ';
            return (1);
        }
        y += 1;
    }
    return (0);
}