/*
** EPITECH PROJECT, 2023
** osef
** File description:
** osef
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#ifndef MY_H_
    #define MY_H_

typedef struct Image {
    sfSprite *sprite;
    sfVector2f start;
    sfVector2f end;
    int time;
    double vitesse;
    double angle;
    sfCircleShape *zone;
    sfRectangleShape *rect;
    int crash;
    int niveau;
    struct Image *next;
} imageinfo;

typedef struct truc {
    sfVector2f start;
    sfVector2f end;
    int vitesse;
    int time;
    struct truc *next;
} linked_list_t;

typedef struct id {
    int coor;
    struct id *next;
} linked_list_id;

typedef struct parametre {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    imageinfo *avion;
    imageinfo *tour;
    sfSprite *world;
    sfIntRect *vchiffre;
    sfMusic *music;
    sfText *text;
    int touche_sprite;
    int touche_rc;
    int lavion;
    int ltour;
    int taille_fond[2];
    int black;
    int arrive;
    sfClock *chrono;
} parametre_t;

typedef struct truc2 {
    int id;
    struct truc2 *next;
} linked_list_tmp;

void ajuste_fond(parametre_t *p);
imageinfo *my_params_to_list(char ***av, char deteminant);
int getnbr(char const *str);
char *my_strdup(char const *src);
int my_put_in_list(linked_list_tmp **list, int nb);
int len_linked_list_t(imageinfo *list);
int len_linked_list_tmp(linked_list_tmp *list);
char *my_strcpy(char *dest, char const *src);
int strl(char const *str);
void my_rev_list(linked_list_tmp **begin);
char *my_strnncpy(char *dest, char const *src, int n2, int n);
void letsbeguinthegame(parametre_t *p);
void playmusic(char *chemin, int x);
void event(parametre_t *p);
parametre_t *initialisation_windows(char ***info);
void disp_sprite(parametre_t *p);
void avanceravion(parametre_t *p);
int colition(imageinfo *avion, imageinfo *tour);
int end_avion(imageinfo **head);
int condition(imageinfo *list);
int str_isnum(char const *str);
char *my_int_to_char1(long long a);
char *my_strrevcat(char *a, char *b);
char *my_int_to_char(long long a);
char *my_revstr(char *str);
char *my_int_to_char(long long a);
int my_strlen(char const *str);
int pnbr(int nb);
void pchar(char c);
#endif /* MY_H_ */
