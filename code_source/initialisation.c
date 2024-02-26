/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"

sfVideoMode mode = {1920, 1080, 32};

static sfText *text(void)
{
    sfFont* font = sfFont_createFromFile("source/Game Of Squids.ttf");
    sfText* text = sfText_create();

    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){10.0f, 10.0f});
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, sfBlack);
    return text;
}

parametre_t *initialisation_windows(char ***info)
{
    parametre_t *paramètres = malloc(sizeof(parametre_t));

    paramètres->mode = mode;
    paramètres->avion = my_params_to_list(info, 'A');
    paramètres->tour = my_params_to_list(info, 'T');
    paramètres->world = sfSprite_create();
    paramètres->text = text();
    paramètres->touche_rc = 1;
    paramètres->touche_sprite = 1;
    sfSprite_setTexture(paramètres->world, sfTexture_createFromFile
    ("source/world.png", NULL), NULL);
    paramètres->window = sfRenderWindow_create(paramètres->mode,
    "My_radar", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(paramètres->window, 32);
    paramètres->black = 0;
    paramètres->arrive = 0;
    paramètres->chrono = sfClock_create();
    return paramètres;
}
