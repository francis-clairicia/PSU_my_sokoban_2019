/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** find_boxes.c
*/

#include "my_sokoban.h"

static int count_boxes(map_t *map)
{
    int count = 0;
    int x = 0;
    int y = 0;

    while (y < map->nb_lines) {
        if (map->str[y][x] == 'X')
            count += 1;
        x += 1;
        if (x == map->nb_columns[y]) {
            x = 0;
            y += 1;
        }
    }
    return (count);
}

static void fill_boxes(map_t *map)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (y < map->nb_lines) {
        if (map->str[y][x] == 'X') {
            (map->boxes[i]).x = x;
            (map->boxes[i]).y = y;
            map->str[y][x] = ' ';
            i += 1;
        }
        x += 1;
        if (x == map->nb_columns[y]) {
            x = 0;
            y += 1;
        }
    }
}

int find_boxes(map_t *map)
{
    int count = count_boxes(map);

    if (count == 0)
        return (0);
    map->nb_boxes = count;
    map->boxes = malloc(sizeof(vector_t) * count);
    if (map->boxes == NULL)
        return (0);
    fill_boxes(map);
    return (1);
}

int char_is_box(map_t *map, vector_t pos)
{
    int i = 0;

    while (i < map->nb_boxes) {
        if (map->boxes[i].x == pos.x && map->boxes[i].y == pos.y)
            return (i);
        i += 1;
    }
    return (-1);
}