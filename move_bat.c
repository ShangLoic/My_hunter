/*
** EPITECH PROJECT, 2023
** Initialisation.c
** File description:
** caac
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

sfIntRect init_rect(mv_t move, int i)
{
    move.a.height = i;
    move.a.left = i * move.c;
    move.a.top = 0;
    move.a.width = i;
    return move.a;
}

mv_t init_move(mv_t move)
{
    move.clock = sfClock_create();
    move.c = 0;
    move.a.height = 130;
    move.a.top = 0;
    move.a.left = 0;
    move.a.width = 130;
    move.x = 1800;
    move.y = 700;
    return move;
}

void icon_set(sfRenderWindow *window)
{
    sfImage *icon = sfImage_createFromFile("./Images/icon.png");

    sfRenderWindow_setIcon(window, 512, 512, sfImage_getPixelsPtr(icon));
}
