/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_player.c
*/

#include "my_sokoban.h"

static void check_box_movable(map_t *map, int index_box)
{
    int x = map->boxes[index_box].pos.x;
    int y = map->boxes[index_box].pos.y;
    char left = map->str[y][x - 1];
    char right = map->str[y][x + 1];
    char top = map->str[y - 1][x];
    char bottom = map->str[y + 1][x];

    if ((my_find_char("#X", left) >= 0
    && (my_find_char("#X", top) >= 0 || my_find_char("#X", bottom) >= 0))
    || (my_find_char("#X", right) >= 0
    && (my_find_char("#X", top) >= 0 || my_find_char("#X", bottom) >= 0)))
        map->boxes[index_box].movable = FALSE;
}

static int move_box(map_t *map, int index_box, vector_t move)
{
    vector_t new_pos;

    if (index_box < 0)
        return (1);
    new_pos.x = map->boxes[index_box].pos.x + move.x;
    new_pos.y = map->boxes[index_box].pos.y + move.y;
    if (map->str[new_pos.y][new_pos.x] == '#'
    || char_is_box(map, new_pos) >= 0)
        return (0);
    map->boxes[index_box].pos = new_pos;
    check_box_movable(map, index_box);
    return (1);
}

static void move_player_coords(map_t *map, vector_t move)
{
    vector_t new_pos = {map->player.x + move.x, map->player.y + move.y};

    if (new_pos.y < 0 || new_pos.y >= map->nb_lines)
        return;
    if (new_pos.x < 0 || new_pos.x >= map->nb_columns[new_pos.y])
        return;
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