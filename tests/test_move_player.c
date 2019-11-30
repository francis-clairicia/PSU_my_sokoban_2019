/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_move_player.c
*/

#include <criterion/criterion.h>
#include "my_sokoban.h"

char *map_for_test(int map_id);

static void action_on_player(map_t *map)
{
    int down[4] = {0, 1, 0, 0};
    int left[4] = {0, 0, 1, 0};
    int right[4] = {0, 0, 0, 1};
    int i = 0;

    move_player(map, left);
    move_player(map, down);
    move_player(map, down);
    move_player(map, down);
    move_player(map, left);
    move_player(map, left);
    while (i < 10) {
        move_player(map, right);
        i += 1;
    }
}

Test(move_player, move_the_player_on_the_map)
{
    map_t *map = get_map(map_for_test(1));
    vector_t final_pos = {11, 6};

    action_on_player(map);
    cr_expect(map->player.x == final_pos.x && map->player.y == final_pos.y);
    free_map(map);
}