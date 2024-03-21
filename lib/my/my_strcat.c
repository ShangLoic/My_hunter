/*
** EPITECH PROJECT, 2023
** my_compute_power
** File description:
** my_compute_power
*/
#include <stdio.h>
#include "my.h"
#include <stdlib.h>
char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0') {
        a++;
    }
    dest = malloc(sizeof(char) * 100);
    while (src[b] != '\0') {
        dest[a + b] = src[b];
        b++;
    }
    return dest;
}
