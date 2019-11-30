/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** char_is_box.c
*/

#include "my_sokoban.h"

int char_is_box(map_t *map, vector_t pos)
{
    int i = 0;

    while (i < map->nb_boxes) {
        if (map->boxes[i].x == pos.x && map->boxes[i].y == pos.y)
            return (i);
        i += 1;
    }
    return (-1);
}