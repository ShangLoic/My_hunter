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

int tri_expoo(char type, va_list list, int a)
{
    double recup;

    switch (type) {
    case 'E':
        recup = va_arg(list, double);
        my_put_expoo(recup, 0, 'E', a);
        break;
    }
    return 0;
}

int tri_e(char type, va_list list, int a)
{
    double recup;

    switch (type) {
    case 'e':
        recup = va_arg(list, double);
        my_put_expoo(recup, 0, 'e', a);
        break;
    default:
        return tri_expoo(type, list, a);
    }
    return 0;
}
