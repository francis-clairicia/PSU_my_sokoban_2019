/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** error_handling.c
*/

#include "my_sokoban.h"

int valid_map(map_t *map)
{
    if (!valid_characters(map))
        return (free_map_and_returns(map, 0));
    if (!find_player(map) || !find_boxes(map) || !find_hole(map))
        return (free_map_and_returns(map, 0));
    return (1);
}