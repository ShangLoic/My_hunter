/*
** EPITECH PROJECT, 2023
** My_Hunter
** File description:
** Jeu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>


sfRenderWindow *window_creating(int lon, int larg, int bpp)
{
    sfVideoMode mode = {lon, larg, bpp};

    return sfRenderWindow_create(mode, "My_Hunter", sfResize | sfClose, NULL);
}

void close_btn(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void destroy_fct(bg_t a)
{
    sfSprite_destroy(a.Sprite);
    sfTexture_destroy(a.Texture);
    sfImage_destroy(a.Image);
}
