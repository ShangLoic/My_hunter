/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Workshop
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#pragma once

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
char *int_to_str(int num);
int my_put_num(long nb);
int pointa(const char *format, int i);
int pointi(const char *format, int i);
char *tri_s(char type, va_list list, int a);
int tri_c(char type, va_list list, int a);
int tri_i_d(char type, va_list list, int a);
int tri_pc(char type, va_list list, int a);
int tri_flt(char type, va_list list, int a);
int tri_o(char type, va_list list, int a);
int tri_u(char type, va_list list, int a);
int tri_x(char type, va_list list, int a);
int tri_p(char type, va_list list, int a);
int tri_expoo(char type, va_list list, int a);
int tri_e(char type, va_list list, int a);
int my_put_flt(double f, int i);
int aff(int a, int b, double f, int i);
void tri_zob(int base, int b, int y);
int zixzoux(long a, int base, int y);
int my_put_expoo(double f, int i, char e, int a);
int counti(int count);
void le_e(char e);
void bicboc(long i, int a);
