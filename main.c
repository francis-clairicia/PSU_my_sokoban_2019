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
    endwin();
}

static char *open_map(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat statbuf;
    char *str;
    int size;

    if (fstat(fd, &statbuf) < 0)
        return (NULL);
    str = malloc(sizeof(char) * (statbuf.st_size + 1));
    if (str != NULL) {
        size = read(fd, str, statbuf.st_size);
        str[size] = 0;
    }
    close(fd);
    return (str);
}

int main(int ac, char **av)
{
    char *buffer;
    int output;

    if (ac != 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0)
        return (print_help());
    buffer = open_map(av[1]);
    init_curs_module();
    output = my_sokoban(get_map(buffer));
    stop_curs_module();
    free(buffer);
    return (output);
}