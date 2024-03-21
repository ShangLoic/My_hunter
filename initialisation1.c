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

void sprite_display(sfSprite *sp, sfTexture *t, sfVector2f p, sfVector2f sc)
{
    sfSprite_setTexture(sp, t, sfFalse);
    sfSprite_setScale(sp, sc);
    sfSprite_setPosition(sp, p);
}

bg_t init_scale(bg_t a, double x, double y)
{
    sfVector2f scale;

    scale.x = x;
    scale.y = y;
    a.Scale = scale;
    return a;
}

bg_t init_position(bg_t a, double x, double y, char *path)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    a.Image = sfImage_createFromFile(path);
    a.Texture = TCFF(path, NULL);
    a.Sprite = sfSprite_create();
    a.Position = position;
    sprite_display(a.Sprite, a.Texture, a.Position, a.Scale);
    return a;
}

hb_t init_hitb(sfRenderWindow *window, bg_t a, sfEvent event)
{
    hb_t box;

    box.pos = sfMouse_getPositionRenderWindow(window);
    box.img = sfSprite_getGlobalBounds(a.Sprite);
    box.mse = MPTC(window, box.pos, NULL);
    return box;
}

ca chacal2(ca a)
{
    a.text = init_txt_t(a.text, "Score :", "./Font/Score.ttf", 100);
    a.slime_rect.height = 100;
    a.slime_rect.left = 0;
    a.slime_rect.top = 300;
    a.slime_rect.width = 75;
    a.text_pos.x = 840;
    a.text_pos.y = 400;
    a.score = 0;
    a.boss = init_scale(a.boss, 4, 4);
    a.boss = init_position(a.boss, -220, 750, "./Images/Walk.png");
    a.boss_rect.height = 65;
    a.boss_rect.left = 0;
    a.boss_rect.top = 63;
    a.boss_rect.width = 65;
    a.boss_health = 80;
    a.boss_speed = 5;
    a.boss_bar = init_scale(a.boss_bar, a.boss_health / 16, 0.3);
    a.boss_bar = init_position(a.boss_bar, 440, 50, "./Images/hp_bar.png");
    return a;
}
