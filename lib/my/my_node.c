/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_node.c
*/

#include "mylist.h"

static list_t *search_node(list_t *begin, int index_searched)
{
    int i = 0;

    while (i != index_searched) {
        begin = begin->next;
        i += 1;
    }
    return (begin);
}

list_t *my_node(list_t *begin, int i)
{
    int list_size = my_list_size(begin);
    list_t *node = NULL;

    if (list_size == 0)
        return (NULL);
    if (i >= list_size || i < (-list_size))
        return (NULL);
    if (i >= 0)
        node = search_node(begin, i);
    else
        node = search_node(begin, list_size + i);
    return (node);
}