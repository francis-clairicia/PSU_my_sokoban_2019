/*
** EPITECH PROJECT, 2019
** My_Lib_C
** File description:
** my_concat_str_list.c
*/

#include <mylist.h>

static int get_str_size(list_t *begin)
{
    int str_size = 0;

    while (begin != NULL) {
        str_size += my_strlen((char *)(begin->data));
        begin = begin->next;
    }
    return (str_size);
}

char *my_concat_str_list(list_t *begin)
{
    int str_size = get_str_size(begin);
    char *str = malloc(sizeof(char) * (str_size + 1));
    int i = 0;
    int j = 0;
    char *element;

    while (begin != NULL) {
        element = (char *)(begin->data);
        while (element[j] != '\0') {
            str[i] = element[j];
            i += 1;
            j += 1;
        }
        j = 0;
        begin = begin->next;
    }
    str[str_size] = 0;
    return (str);
}