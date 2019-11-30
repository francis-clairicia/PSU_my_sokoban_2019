/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_map_validity.c
*/

#include <criterion/criterion.h>
#include "my_sokoban.h"

char *map_for_test(int map_id);

Test(get_map, handle_non_valid_char)
{
    map_t *map = get_map(map_for_test(2));

    cr_expect_null(map);
}

Test(get_map, handle_no_player)
{
    map_t *map = get_map(map_for_test(3));

    cr_expect_null(map);
}

Test(get_map, handle_no_boxes)
{
    map_t *map = get_map(map_for_test(4));

    cr_expect_null(map);
}

Test(get_map, handle_no_holes)
{
    map_t *map = get_map(map_for_test(5));

    cr_expect_null(map);
}

Test(get_map, handle_different_number_of_boxes_and_holes)
{
    map_t *map = get_map(map_for_test(6));

    cr_expect_null(map);
}