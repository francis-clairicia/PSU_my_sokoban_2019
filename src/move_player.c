/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_player.c
*/

#include "my_sokoban.h"

static int move_box(map_t *map, int index_box, vector_t move)
{
    vector_t new_pos;

    if (index_box < 0)
        return (1);
    new_pos.x = map->boxes[index_box].x + move.x;
    new_pos.y = map->boxes[index_box].y + move.y;
    if (map->str[new_pos.y][new_pos.x] == '#' || char_is_box(map, new_pos) >= 0)
        return (0);
    map->boxes[index_box] = new_pos;
    return (1);
}

static void move_player_coords(map_t *map, vector_t move)
{
    vector_t new_pos = {map->player.x + move.x, map->player.y + move.y};

    if (map->str[new_pos.y][new_pos.x] == '#')
        return;
    if (!move_box(map, char_is_box(map, new_pos), move))
        return;
    map->player = new_pos;
}

void move_player(map_t *map, int *direction)
{
    int i = 0;
    vector_t move[4] = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };

    while (i < 4) {
        if (direction[i] == 1)
            move_player_coords(map, move[i]);
        i += 1;
    }
}