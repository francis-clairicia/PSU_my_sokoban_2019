/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_sokoban.c
*/

#include "my_sokoban.h"

static void get_direction(int key, int *direction)
{
    direction[0] = (key == KEY_UP);
    direction[1] = (key == KEY_DOWN);
    direction[2] = (key == KEY_LEFT);
    direction[3] = (key == KEY_RIGHT);
}

int my_sokoban(map_t *map)
{
    int key = 0;
    int direction[4];

    if (!find_player(map) || !find_boxes(map))
        return (free_map_and_returns(map, 84));
    while (key != ' ') {
        draw_map(map);
        key = getch();
        get_direction(key, direction);
        move_player(map, direction);
    }
    return (free_map_and_returns(map, 0));
}