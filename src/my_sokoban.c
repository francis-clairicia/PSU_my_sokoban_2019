/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_sokoban.c
*/

#include "my_sokoban.h"

static void init_curs_module(void)
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(500);
}

static void stop_curs_module(void)
{
    clrtoeol();
    refresh();
    endwin();
}

static void get_direction(int key, int *direction)
{
    direction[0] = (key == KEY_UP);
    direction[1] = (key == KEY_DOWN);
    direction[2] = (key == KEY_LEFT);
    direction[3] = (key == KEY_RIGHT);
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
    char key_to_quit = 'q';

    if (map == NULL)
        return (84);
    init_curs_module();
    while (key != key_to_quit) {
        draw_map(map);
        key = getch();
        if (key != key_to_quit) {
            get_direction(key, direction);
            move_player(map, direction);
        }
        if (key == ' ')
            reload_map(&map);
    }
    stop_curs_module();
    return (free_map_and_returns(map, 0));
}