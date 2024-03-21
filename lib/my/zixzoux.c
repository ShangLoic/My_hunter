/*
** EPITECH PROJECT, 2023
** tri_o_u_x
** File description:
** jhgfd
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void tri_zob(int base, int b, int y)
{
    char *minu = "0123456789abcdef";
    char *manu = "0123456789ABCDEF";

    if (y == 1) {
        my_putchar(manu[b]);
    } else {
        my_putchar(minu[b]);
    }
}

int zixzoux(long a, int base, int y)
{
    double f = a;
    int i = 0;
    int b;

    while (f > base) {
        f /= base;
        i++;
    }
    while (i >= 0) {
        a = f;
        b = a % base;
        tri_zob(base, b, y);
        f *= base;
        i--;
    }
    return 0;
}
