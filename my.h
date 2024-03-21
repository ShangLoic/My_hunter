/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Workshop
*/

#pragma once
#define TCFF sfTexture_createFromFile
#define SBCF sfSoundBuffer_createFromFile
#define MPTC sfRenderWindow_mapPixelToCoords
#define CROSS "./Images/crosshair.png"
#define CBM cut.bx.pos
#define BACK background
#define SLBX cut.bx_slime.mse
#define CONT sfFloatRect_contains
#define CBBM cut.bx_boss.mse
#define SSST sfSprite_setTexture
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

typedef struct anim {
    sfClock *clock;
    int c;
    sfIntRect a;
    double x;
    double y;
} mv_t;

typedef struct entity {
    sfTexture *Texture;
    sfSprite *Sprite;
    sfVector2f Position;
    sfVector2f Scale;
    sfImage *Image;
} bg_t;

typedef struct Text {
    sfText *text;
    sfFont *font;
    char *str;
    int size;
} txt_t;

typedef struct hitbox {
    sfVector2i pos;
    sfFloatRect img;
    sfVector2f mse;
}hb_t;

typedef struct raccourci {
    bg_t background;
    bg_t bat;
    bg_t slime;
    mv_t slime_move;
    mv_t move;
    hb_t bx;
    hb_t bx_slime;
    bg_t cross;
    int life;
    bg_t heart;
    sfIntRect vie;
    int x;
    txt_t text;
    int score;
    sfIntRect slime_rect;
    sfVector2f text_pos;
    bg_t boss;
    mv_t boss_move;
    hb_t bx_boss;
    sfIntRect boss_rect;
    double boss_health;
    int boss_speed;
    bg_t boss_bar;
} ca;

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int n);
bg_t init_scale(bg_t a, double x, double y);
bg_t init_position(bg_t a, double x, double y, char *path);
void Sprite_Display(sfSprite *sp, sfTexture *t, sfVector2f p, sfVector2f sc);
txt_t init_txt_t(txt_t a, char *str, char *path, int size);
hb_t init_hitbox(sfRenderWindow *window, bg_t pressed);
txt_t Text_Display(txt_t a, int x, int y);
ca on_click(sfRenderWindow *window, sfEvent event, ca cut);
sfIntRect init_rect(mv_t move, int i);
mv_t init_move(mv_t move);
bg_t cut1(sfRenderWindow *window, bg_t background);
hb_t init_hitb(sfRenderWindow *window, bg_t a, sfEvent event);
double high(double y);
ca longu(ca cut, int x);
ca anim(ca cut, bg_t bat, int x);
sfRenderWindow *window_creating(int lon, int larg, int bpp);
void close_btn(sfRenderWindow *window, sfEvent event);
void destroy_fct(bg_t a);
void start_music(sfBool A);
sfSound *sound_btn(void);
int music_btn(sfRenderWindow *window, sfEvent event);
void game_display(sfRenderWindow *window, sfEvent event);
int my_hunter(void);
ca chacal(ca a, sfRenderWindow *window);
ca chacal2(ca a);
int lore(char **av);
void cutter(sfRenderWindow *window, ca cut);
int replay_btn(sfRenderWindow *window, sfEvent event);
void racc(sfRenderWindow *window, ca cut);
char *int_to_str(int num);
int my_restart(sfRenderWindow *window, sfEvent event, ca cut);
void racc(sfRenderWindow *window, ca cut);
ca slime_fct(ca cut);
void icon_set(sfRenderWindow *window);
int hunter_disp(sfRenderWindow *window, sfEvent event, bg_t BACK, bg_t icon);
int play_btn(sfRenderWindow *window, sfEvent event);
bg_t cut1(sfRenderWindow *window, bg_t BACK);
ca boss_fct(ca cut);
void disp_txt(ca cut, sfRenderWindow *window, sfEvent event);
bg_t setup(sfRenderWindow *window, bg_t icon);
