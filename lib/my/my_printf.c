/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** afzl
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_printf(char const *format, ...)
{
    int i;
    va_list list;
    int a;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            a = pointa(format, i);
            i = pointi(format, i);
            tri_flt(format[i], list, a);
        } else {
            my_putchar(format[i]);
        }
        i++;
    }
    return 0;
}
