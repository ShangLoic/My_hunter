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
#include <stdlib.h>

bg_t setup(sfRenderWindow *window, bg_t icon)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    start_music(sfTrue);
    icon = init_position(icon, 760, 200, "./Images/icon.png");
    icon_set(window);
    return icon;
}
