/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_list.c
*/

#include <mylist.h>
#include <stdarg.h>

list_t *my_list(int nb_element, ...)
{
    va_list ap;
    list_t *list = NULL;
    long element;
    int i = 0;

    va_start(ap, nb_element);
    while (i < nb_element) {
        element = va_arg(ap, long);
        my_put_in_list(&list, element);
        i += 1;
    }
    return (list);
}