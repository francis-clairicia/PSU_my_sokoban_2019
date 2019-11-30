/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_get_map.c
*/

#include <criterion/criterion.h>
#include "my_sokoban.h"

char *map_for_test(int map_id);

Test(get_map, read_the_map_file)
{
    char *map_expected[] = {
        "##############",
        "#            #",
        "#            #",
        "#      ####  #",
        "#    ###  ####",
        "#            #",
        "#O          O#",
        "##############" };
    int nb_columns_expected[] = {14, 14, 14, 14, 14, 14, 14, 14};
    int i = 0;
    map_t *map = get_map(map_for_test(1));

    cr_expect_eq(map->nb_lines, 8);
    cr_expect_eq(map->max_nb_columns, 14);
    while (i < map->nb_lines) {
        cr_expect_str_eq((map->str)[i], map_expected[i]);
        i += 1;
    }
    cr_expect_arr_eq(map->nb_columns, nb_columns_expected, 8);
    free_map(map);
}

Test(get_map, handle_non_existing_files)
{
    map_t *map = get_map(NULL);

    cr_expect_null(map);
}

Test(get_map, handle_empty_map)
{
    map_t *map = get_map("");

    cr_expect_null(map);
}