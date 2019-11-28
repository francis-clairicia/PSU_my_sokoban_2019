/*
** EPITECH PROJECT, 2019
** my_concat_list
** File description:
** Concatenate two linked lists
*/

#include <mylist.h>

void my_concat_list(list_t **begin1, list_t *begin2)
{
    list_t *tmp;

    if ((*begin1) == NULL) {
        (*begin1) = begin2;
    } else {
        tmp = (*begin1);
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = begin2;
        begin2->previous = tmp;
    }
}
