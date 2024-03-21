/*
** EPITECH PROJECT, 2023
** qegsrhdty
** File description:
** grhtryt,u
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *tri_s(char type, va_list list, int a)
{
    char *recup;
    int i = 0;

    switch (type) {
    case 's':
        recup = (char *)va_arg(list, char *);
        if (a == 0) {
            a = 10000;
        }
        while (a > i && recup[i] != '\0') {
            my_putchar(recup[i]);
            i++;
        }
        break;
    default:
        tri_p(type, list, a);
    }
    return recup;
}

int tri_c(char type, va_list list, int a)
{
    char recup;

    switch (type) {
    case 'c':
        recup = (char)va_arg(list, int);
        my_putchar(recup);
        return 1;
        break;
    default:
        tri_s(type, list, a);
    }
}

int tri_i_d(char type, va_list list, int a)
{
    long i;

    switch (type) {
    case 'd':
    case 'i':
        i = va_arg(list, int);
        bicboc(i, a);
        return 0;
    default:
        tri_c(type, list, a);
    }
}

int tri_pc(char type, va_list list, int a)
{
    switch (type) {
    case '%':
        my_putchar('%');
        return 1;
        break;
    default:
        return tri_i_d(type, list, a);
    }
}

int tri_flt(char type, va_list list, int a)
{
    double recup;

    switch (type) {
    case 'f':
        recup = va_arg(list, double);
        return my_put_flt(recup, a);
        break;
    default:
        return tri_pc(type, list, a);
    }
}
