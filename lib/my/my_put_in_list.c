/*
** EPITECH PROJECT, 2019
** my_put_in_list
** File description:
** Put an element into a list
*/

#include <mylist.h>

int my_put_in_list(list_t **list, long data)
{
    list_t *element = malloc(sizeof(list_t));

    if (element != NULL) {
        element->data = data;
        element->previous = NULL;
        element->next = *list;
        *list = element;
        return (0);
    }
    return (1);
}
