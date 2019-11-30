/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** get_map.c
*/

#include "my_sokoban.h"

static int count_lines(char const *buffer)
{
    int i = 0;
    int nb_lines = 0;

    if (buffer == NULL)
        return (-1);
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            nb_lines += 1;
        i += 1;
    }
    return (nb_lines);
}

static map_t *init_map(int nb_lines)
{
    map_t *map;

    if (nb_lines < 0)
        return (NULL);
    map = malloc(sizeof(map_t));
    if (map == NULL)
        return (NULL);
    map->nb_lines = nb_lines;
    map->nb_columns = malloc(sizeof(int) * nb_lines);
    map->boxes = NULL;
    map->max_nb_columns = -1;
    map->str = malloc(sizeof(char *) * nb_lines);
    if (map->nb_columns == NULL || map->str == NULL)
        return ((void *)free_map_and_returns(map, 0));
    return (map);
}

static void fill_map(map_t *map, char const *buffer)
{
    int i = 0;
    int nb_columns = 0;

    while (i < map->nb_lines) {
        nb_columns = my_find_char(buffer, '\n');
        (map->str)[i] = my_strndup(buffer, nb_columns);
        (map->nb_columns)[i] = nb_columns;
        if (nb_columns > map->max_nb_columns)
            map->max_nb_columns = nb_columns;
        i += 1;
        buffer = &buffer[nb_columns + 1];
    }
}

map_t *get_map(char const *buffer)
{
    map_t *map = init_map(count_lines(buffer));

    if (map == NULL)
        return (NULL);
    fill_map(map, buffer);
    map->buffer = buffer;
    if (!valid_map(map))
        return (NULL);
    return (map);
}