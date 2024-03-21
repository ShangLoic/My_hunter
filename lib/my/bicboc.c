/*
** EPITECH PROJECT, 2023
** bocbic.c
** File description:
** efgrhtj
*/
#include "my.h"

void bicboc(long i, int a)
{
    long d;

    if (i < 0) {
        i *= -1;
        my_putchar('-');
    }
    d = i;
    while (d > 0) {
        d /= 10;
        a--;
    }
    while (a > 0) {
        a--;
        my_putchar('0');
    }
    my_put_num(i);
}
