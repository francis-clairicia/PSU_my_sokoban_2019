/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** error_handling.c
*/

#include "my_sokoban.h"

static int valid_nb_columns(map_t *map)
{
    int i = 0;

    while (i < map->nb_lines) {
        if (map->nb_columns[i] == 0)
            return (0);
        i += 1;
    }
    return (1);
}

int valid_map(map_t *map)
{
    if (!valid_characters(map) || !valid_nb_columns(map))
        return (free_map_and_returns(map, 0));
    if (!find_player(map) || !find_boxes(map) || !find_hole(map))
        return (free_map_and_returns(map, 0));
    return (1);
}