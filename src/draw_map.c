/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** draw_map.c
*/

#include "my_sokoban.h"

static vector_t get_first_char_pos(map_t *map)
{
    int nb_lines = map->nb_lines;
    int nb_columns = map->max_nb_columns;
    vector_t coords;

    coords.x = (COLS - nb_columns) / 2;
    coords.y = (LINES - nb_lines) / 2;
    return (coords);
}

static void draw_player(vector_t player, int x, int y)
{
    mvprintw(player.y + y, player.x + x, "P");
}

static void draw_boxes(box_t *boxes, int nb_boxes, int x, int y)
{
    int i = 0;

    while (i < nb_boxes) {
        mvprintw(boxes[i].pos.y + y, boxes[i].pos.x + x, "X");
        i += 1;
    }
}

void draw_map(map_t *map)
{
    vector_t coords = get_first_char_pos(map);
    int line = 0;

    clear();
    if (!(map->printable)) {
        mvprintw(0, 0, "Agrandis ce putain\nde terminal");
        return;
    }
    while (line < map->nb_lines) {
        mvprintw(coords.y + line, coords.x, map->str[line]);
        line += 1;
    }
    draw_boxes(map->boxes, map->nb_boxes, coords.x, coords.y);
    draw_player(map->player, coords.x, coords.y);
    refresh();
}