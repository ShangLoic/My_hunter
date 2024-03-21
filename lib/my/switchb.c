/*
** EPITECH PROJECT, 2023
** switchb
** File description:
** zehtrjf
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int tri_u(char type, va_list list, int a)
{
    int recup;

    switch (type) {
    case 'u':
        recup = va_arg(list, int);
        zixzoux(recup, 10, 0);
        break;
    default:
        return tri_e(type, list, a);
    }
    return 0;
}

int tri_o(char type, va_list list, int a)
{
    int recup;

    switch (type) {
    case 'o':
        recup = va_arg(list, int);
        zixzoux(recup, 8, 1);
        break;
    default:
        return tri_u(type, list, a);
    }
    return 0;
}

int tri_x(char type, va_list list, int a)
{
    int recup;

    switch (type) {
    case 'x':
        recup = va_arg(list, int);
        zixzoux(recup, 16, 0);
        break;
    case 'X':
        recup = va_arg(list, int);
        zixzoux(recup, 16, 1);
        break;
    default:
        return tri_o(type, list, a);
    }
    return 0;
}

int tri_p(char type, va_list list, int a)
{
    long recup;

    switch (type) {
    case 'p':
        recup = va_arg(list, long);
        my_putstr("0x");
        zixzoux(recup, 16, 0);
    default:
        return tri_x(type, list, a);
    }
    return 0;
}
