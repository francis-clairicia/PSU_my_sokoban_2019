/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** map_valid.c
*/

char *return_valid_map(void);
char *return_invalid_map(void);
char *return_map_with_no_player(void);
char *return_map_with_no_boxes(void);
char *return_map_with_no_holes(void);
char *return_map_with_different_nb_boxes_holes(void);

char *map_for_test(int map_id)
{
    char *(*map_to_return[])(void) = {
        return_valid_map,
        return_invalid_map,
        return_map_with_no_player,
        return_map_with_no_boxes,
        return_map_with_no_holes,
        return_map_with_different_nb_boxes_holes
    };

    return (map_to_return[map_id - 1]());
}