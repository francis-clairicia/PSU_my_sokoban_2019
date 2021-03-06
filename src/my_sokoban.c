/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_sokoban.c
*/

#include "my_sokoban.h"

static void is_printable(map_t *map)
{
    int nb_lines = map->nb_lines;
    int nb_columns = map->max_nb_columns;

    map->printable = ((LINES >= nb_lines) && (COLS >= nb_columns));
}

static void get_direction(int key, int *direction, int map_printable)
{
    direction[0] = (key == KEY_UP && map_printable);
    direction[1] = (key == KEY_DOWN && map_printable);
    direction[2] = (key == KEY_LEFT && map_printable);
    direction[3] = (key == KEY_RIGHT && map_printable);
}

static void reload_map(map_t **map)
{
    char const *buffer = (*map)->buffer;

    free_map(*map);
    *map = get_map(buffer);
}

int my_sokoban(map_t *map)
{
    int key = 0;
    int direction[4];
    int output = -1;

    if (map == NULL)
        return (84);
    while (key != 'q' && output < 0) {
        is_printable(map);
        draw_map(map);
        output = check_game_status(map);
        key = getch();
        get_direction(key, direction, map->printable);
        move_player(map, direction);
        if (key == ' ')
            reload_map(&map);
    }
    return (free_map_and_returns(map, (output < 0) ? 0 : output));
}