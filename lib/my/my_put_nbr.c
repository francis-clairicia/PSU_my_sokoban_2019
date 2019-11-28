/*
** EPITECH PROJECT, 2019
** Put number
** File description:
** Display number entered as parameter
*/

#include <my.h>

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}
