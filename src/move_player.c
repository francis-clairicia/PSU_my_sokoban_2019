/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move_player.c
*/

#include "my_sokoban.h"

static void check_if_box_is_movable(char **map, box_t *boxes, int index_box)
{
    vector_t pos = boxes[index_box].pos;
    vector_t left = {pos.x - 1, pos.y};
    vector_t right = {pos.x + 1, pos.y};
    vector_t top = {pos.x, pos.y - 1};
    vector_t bottom = {pos.x, pos.y + 1};
    int blocked = 0;

    if (my_find_char("#X", map[left.y][left.x]) >= 0
    && (my_find_char("#X", map[top.y][top.x]) >= 0
    || my_find_char("#X", map[bottom.y][bottom.x]) >= 0))
        blocked = 1;
    if (my_find_char("#X", map[right.y][right.x]) >= 0
    && (my_find_char("#X", map[top.y][top.x]) >= 0
    || my_find_char("#X", map[bottom.y][bottom.x]) >= 0))
        blocked = 1;
    boxes[index_box].movable = !blocked;
}

static int move_box(map_t *map, int index_box, vector_t move)
{
    vector_t new_pos;

    if (index_box < 0)
        return (1);
    new_pos.x = map->boxes[index_box].pos.x + move.x;
    new_pos.y = map->boxes[index_box].pos.y + move.y;
    if (map->str[new_pos.y][new_pos.x] == '#' || char_is_box(map, new_pos) >= 0)
        return (0);
    map->boxes[index_box].pos = new_pos;
    check_if_box_is_movable(map->str, map->boxes, index_box);
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