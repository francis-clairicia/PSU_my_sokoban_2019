/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_get_map.c
*/

#include <criterion/criterion.h>
#include "my_sokoban.h"

Test(get_map, read_the_map_file)
{
    char *map_expected[] = {
        "##############",
        "#            #",
        "#            #",
        "#    P ####  #",
        "#    ###  ####",
        "#            #",
        "#OX        XO#",
        "##############" };
    int nb_columns_expected[] = {15, 15, 15, 15, 15, 15, 15, 15};
    int i = 0;
    map_t *map = get_map("tests/map.txt");

    cr_expect_eq(map->nb_lines, 8);
    cr_expect_eq(map->max_nb_columns, 15);
    while (i < map->nb_lines) {
        cr_expect_str_eq((map->str)[i], map_expected[i]);
        i += 1;
    }
    cr_expect_arr_eq(map->nb_columns, nb_columns_expected, 8);
    free_map(map);
}

Test(get_map, handle_non_valid_char)
{
    char filepath[] = "tests/map_invalid_char.txt";
    map_t *map = get_map(filepath);

    cr_expect_null(map);
}

Test(get_map, handle_non_existing_files)
{
    char filepath[] = "tests/unknown_map.txt";
    map_t *map = get_map(filepath);

    cr_expect_null(map);
}