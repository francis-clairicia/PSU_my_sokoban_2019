/*
** EPITECH PROJECT, 2019
** My put str
** File description:
** Display a string
*/

#include <my.h>

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (my_putstr("NULL"));
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}
