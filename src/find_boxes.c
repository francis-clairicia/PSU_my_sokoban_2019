/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** find_boxes.c
*/

#include "my_sokoban.h"

static int search_boxes(map_t *map, int fill_tab)
{
    int count = 0;
    int x = 0;
    int y = 0;

    while (y < map->nb_lines) {
        if (map->str[y][x] == 'X')
            count += 1;
        if (map->str[y][x] == 'X' && fill_tab) {
            (map->boxes[count - 1]).pos.x = x;
            (map->boxes[count - 1]).pos.y = y;
            map->str[y][x] = ' ';
        }
        x += 1;
        if (x == map->nb_columns[y]) {
            x = 0;
            y += 1;
        }
    }
    return (count);
}

int find_boxes(map_t *map)
{
    int count = search_boxes(map, 0);

    map->nb_boxes = count;
    map->boxes = malloc(sizeof(box_t) * count);
    if (count == 0 || map->boxes == NULL)
        return (0);
    search_boxes(map, 1);
    return (1);
}