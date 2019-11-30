/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** valid_characters.c
*/

#include "my_sokoban.h"

static int line_valid(char const *line)
{
    int i = 0;

    while (line[i] != '\0') {
        if (my_find_char(" PXO#", line[i]) == -1)
            return (0);
        i += 1;
    }
    return (1);
}

int valid_characters(map_t *map)
{
    int i = 0;

    while (i < map->nb_lines) {
        if (!line_valid((map->str)[i]))
            return (0);
        i += 1;
    }
    return (1);
}