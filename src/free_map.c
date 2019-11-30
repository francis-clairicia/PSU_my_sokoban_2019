/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** free_map.c
*/

#include "my_sokoban.h"

void free_map(map_t *map)
{
    int i = 0;

    free(map->nb_columns);
    while (i < map->nb_lines) {
        free((map->str)[i]);
        i += 1;
    }
    free(map->str);
    free(map->boxes);
    free(map);
}

long free_map_and_returns(map_t *map, long status)
{
    free_map(map);
    return (status);
}