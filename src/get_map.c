/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** get_map.c
*/

#include "my_sokoban.h"

static int count_lines(char *str, int size)
{
    int i = 0;
    int nb_lines = 0;

    while (i < size) {
        if (str[i] == '\n')
            nb_lines += 1;
        i += 1;
    }
    free(str);
    return (nb_lines);
}

static int get_number_of_lines(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat statbuf;
    char *str = NULL;
    int size;

    if (fstat(fd, &statbuf) < 0)
        return (-84);
    str = malloc(sizeof(char) * statbuf.st_size);
    size = read(fd, str, statbuf.st_size);
    close(fd);
    return (count_lines(str, size));
}

static map_t *init_map(int nb_lines)
{
    map_t *map;

    if (nb_lines == -84)
        return (NULL);
    map = malloc(sizeof(map_t));
    if (map == NULL)
        return (NULL);
    map->nb_lines = nb_lines;
    map->nb_columns = malloc(sizeof(int) * nb_lines);
    map->max_nb_columns = -1;
    map->str = malloc(sizeof(char *) * nb_lines);
    if (map->nb_columns == NULL || map->str == NULL)
        return ((void *)free_map_and_returns(map, 0));
    return (map);
}

static void fill_map(map_t *map, FILE *stream)
{
    int i = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    while (i < map->nb_lines) {
        nread = getline(&line, &len, stream);
        (map->str)[i] = my_strndup(line, nread - 1);
        (map->nb_columns)[i] = nread;
        if (nread > map->max_nb_columns)
            map->max_nb_columns = nread;
        i += 1;
    }
    free(line);
}

map_t *get_map(char const *filepath)
{
    map_t *map;
    int nb_lines = get_number_of_lines(filepath);
    FILE *stream;

    map = init_map(nb_lines);
    stream = fopen(filepath, "r");
    if (stream == NULL || map == NULL)
        return (NULL);
    fill_map(map, stream);
    fclose(stream);
    if (!valid_map(map))
        return ((void *)free_map_and_returns(map, 0));
    return (map);
}