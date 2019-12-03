/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check_game_status.c
*/

#include "my_sokoban.h"

static int all_boxes_in_holes(map_t *map)
{
    int i = 0;
    vector_t pos;

    while (i < map->nb_boxes) {
        pos = map->boxes[i].pos;
        if (map->str[pos.y][pos.x] != 'O')
            return (0);
        i += 1;
    }
    return (1);
}

static int any_box_can_move(map_t *map)
{
    int i = 0;

    while (i < map->nb_boxes) {
        if (map->boxes[i].movable)
            return (0);
        i += 1;
    }
    return (1);
}

int check_game_status(map_t *map)
{
    if (all_boxes_in_holes(map))
        return (0);
    if (any_box_can_move(map))
        return (1);
    return (-1);
}