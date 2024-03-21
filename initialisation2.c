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

txt_t text_display(txt_t a, int x, int y)
{
    sfVector2f b;

    sfText_setString(a.text, a.str);
    sfText_setFont(a.text, a.font);
    sfText_setCharacterSize(a.text, a.size);
    b.x = x;
    b.y = y;
    sfText_setPosition(a.text, b);
}

txt_t init_txt_t(txt_t a, char *str, char *path, int size)
{
    a.text = sfText_create();
    a.str = str;
    a.font = sfFont_createFromFile(path);
    a.size = size;
    text_display(a, 20, -20);
    return a;
}

hb_t init_hitbox(sfRenderWindow *window, bg_t a)
{
    hb_t box;

    box.pos = sfMouse_getPositionRenderWindow(window);
    box.img = sfSprite_getGlobalBounds(a.Sprite);
    box.mse = MPTC(window, box.pos, NULL);
    return box;
}

ca chacal(ca a, sfRenderWindow *window)
{
    a.BACK = init_scale(a.BACK, 1, 1);
    a.bat = init_scale(a.bat, 1, 1);
    a.slime = init_scale(a.slime, 1, 1);
    a.move = init_move(a.move);
    a.cross = init_scale(a.cross, 1, 1);
    a.heart = init_scale(a.heart, 0.3, 0.3);
    a.life = 3;
    a.vie.height = 300;
    a.vie.left = 0;
    a.vie.top = 0;
    a.vie.width = 300;
    a.heart = init_position(a.heart, 1800, 0, "./Images/heart.png");
    a.BACK = cut1(window, a.BACK);
    a.bat = init_position(a.bat, a.move.x, 555, "./Images/Bat.png");
    a.slime = init_position(a.slime, 1980, 930, "./Images/Bat.png");
    a.x = 22;
    a = chacal2(a);
    return a;
}

void disp_txt(ca cut, sfRenderWindow *window, sfEvent event)
{
    sfText_setPosition(cut.text.text, cut.text_pos);
    sfText_setCharacterSize(cut.text.text, 200);
    sfRenderWindow_drawText(window, cut.text.text, NULL);
    replay_btn(window, event);
    sfRenderWindow_display(window);
}
