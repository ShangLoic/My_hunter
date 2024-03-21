/*
** EPITECH PROJECT, 2023
** detectpoint
** File description:
** agb
*/

#include <stdio.h>

int pointa(char *format, int i)
{
    int a;
    int b = 0;

    if (format[i] == '.') {
        i++;
        while (format[i] >= 48 && format[i] <= 57) {
            a = (a * 10) + (format[i] - 48);
            i++;
        }
    } else if (format[i] == 'f' || format [i] == 'e') {
        return 6;
    }
    return a;
}

int pointi(char *format, int i)
{
    int a = 0;

    if (format[i] == '.') {
        i++;
        while (format[i] >= 48 && format[i] <= 57) {
            a = (a * 10) + (format[i] - 48);
            i++;
        }
    }
    return i;
}
