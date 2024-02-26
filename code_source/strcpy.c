/*
** EPITECH PROJECT, 2023
** ProjectDay03
** File description:
** Copier les caractères de str dans dest
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    return dest;
}
