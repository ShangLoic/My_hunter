/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** task01
*/
#include <unistd.h>

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
