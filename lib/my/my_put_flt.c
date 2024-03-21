/*
** EPITECH PROJECT, 2023
** my_put_nbr_after_comma.c
** File description:
** lib
*/

#include <stdio.h>
#include "my.h"

int aff(int a, int b, double f, int i)
{
    if (i == 0 && f >= 5) {
        a++;
    }
    my_put_nbr(a);
    if (i == b && b >= 1) {
        my_putchar('.');
    }
    return 0;
}

int my_put_flt(double f, int i)
{
    int a;
    int b = i;
    int count = 0;

    if (f < 0) {
        my_putchar('-');
        f *= -1;
    }
    i++;
    while (i != 0) {
        a = f;
        f = (f - a) * 10;
        if (f > 9) {
            f = 0;
            a++;
        }
        i--;
        aff(a, b, f, i);
    }
    return 0;
}
