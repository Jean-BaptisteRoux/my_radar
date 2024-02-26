/*
** EPITECH PROJECT, 2023
** ProjectDay
** File description:
** Ensemble de fonction liées à char
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void my_putchar(char c, int *compteur)
{
    write(1, &c, 1);
    (*compteur)++;
}

static int my_intlen(long long i)
{
    int a;

    if (i == 0)
        return 0;
    for (a = 0; i != 0; a++)
        i = i / 10;
    return (a);
}

int my_isnum(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

static char *my_strcat2(char *dest, char const *src)
{
    int i = 0;
    int a = 0;
    char *r = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (i = 0; dest[i] != '\0'; i++) {
        r[i] = dest[i];
    }
    for (a = 0; src[a] != '\0'; a++) {
        r[i] = src[a];
        i++;
    }
    r[i] = '\0';
    return r;
}

char *my_int_to_char1(long long a)
{
    char *r = malloc(sizeof(char) * (my_intlen(a) + 2));
    int i = 0;
    int neg = 0;

    if (a < 0) {
        neg = 1;
        a = -a;
    }
    for (i = 0; a != 0; i++) {
        r[i] = (a % 10) + 48;
        a = a / 10;
    }
    if (neg == 1) {
        r = my_strcat2(r, "-");
    } else {
        r[i] = '\0';
    }
    r = my_revstr(r);
    return r;
}

void my_int_to_char2(long long *a, int *i, char **r)
{
    for ((*i) = 0; *a != 0; (*i)++) {
        (*r)[*i] = ((*a) % 10) + 48;
        (*a) = (*a) / 10;
    }
}

char *my_int_to_char(long long a)
{
    char *r = malloc(sizeof(char) * (my_intlen(a) + 2));
    int i = 0;
    int neg = 0;

    if (a == 0)
        return "0";
    if (a < 0) {
        neg = 1;
        a = -a;
    }
    my_int_to_char2(&a, &i, &r);
    if (neg == 1) {
        r = my_strcat2(r, "-");
    } else {
        r[i] = '\0';
    }
    r = my_revstr(r);
    return r;
}
