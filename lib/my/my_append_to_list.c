/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_append_to_list.c
*/

#include <mylist.h>

int my_append_to_list(list_t **list, long data)
{
    list_t *element = malloc(sizeof(list_t));

    if (element != NULL) {
        element->data = data;
        element->previous = NULL;
        element->next = NULL;
        my_concat_list(list, element);
        return (0);
    }
    return (1);
}