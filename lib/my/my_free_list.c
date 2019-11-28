/*
** EPITECH PROJECT, 2019
** my_free_list
** File description:
** Free data in list
*/

#include <mylist.h>

void my_free_list(list_t **list, int free_str)
{
    list_t *element;

    while ((*list) != NULL) {
        element = *list;
        *list = (*list)->next;
        if (free_str && (char *)(element->data) != NULL)
            free((char *)(element->data));
        free(element);
    }
}
