/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main.c
*/

#include "my_sokoban.h"

static int print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap   file representing the warehouse map, ");
    my_putstr("containing '#' for walls, \n");
    my_putstr("\t      'P' for the player, ");
    my_putstr("'X' for boxes and 'O' for storage locations.\n");
    return (0);
}

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
    nocbreak();
    echo();
    endwin();
}

int main(int ac, char **av)
{
    map_t *map;
    int output;

    if (ac != 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0)
        return (print_help());
    map = get_map(av[1]);
    if (map == NULL)
        return (84);
    init_curs_module();
    output = my_sokoban(map);
    stop_curs_module();
    return (output);
}