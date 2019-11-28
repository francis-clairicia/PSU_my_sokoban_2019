/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_player.c
*/

#include "my_sokoban.h"

static void move_player_coords(map_t *map, vector_t move)
{
    vector_t new_pos = {map->player.x + move.x, map->player.y + move.y};

    if (map->str[new_pos.y][new_pos.x] == '#')
        return;
    map->player = new_pos;
}

void move_player(map_t *map, int *direction)
{
    int i = 0;
    vector_t move = {0, 0};
    vector_t move_pos[] = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };

    while (i < 4) {
        if (direction[i] == 1)
            move = move_pos[i];
        i += 1;
    }
    move_player_coords(map, move);
}