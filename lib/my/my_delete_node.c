/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_delete_node.c
*/

#include "mylist.h"

void my_delete_node(list_t **list, int i, int free_str)
{
    list_t *node = NULL;

    if (*list == NULL)
        return;
    if (i == 0 || (i < 0 && (my_list_size(*list) + i == 0))) {
        node = (*list)->next;
        my_free_list(list, free_str);
        node->previous = NULL;
        (*list) = node;
        return;
    }
    node = my_node(*list, i);
    (node->previous)->next = node->next;
    my_free_list(&node, free_str);
}

void my_delete_node_from_data(list_t **list, long data, int free_str)
{
    list_t *node = *list;
    int i = 0;

    if (node == NULL)
        return;
    while (node != NULL && node->data != data) {
        node = node->next;
        i += 1;
    }
    if (node == NULL)
        return;
    my_delete_node(list, i, free_str);
}