/*
** EPITECH PROJECT, 2023
** ProjectDay03
** File description:
** Copie jusqu'à n caractère de str dans dest
*/
#include "my.h"

char *my_strnncpy(char *dest, char const *src, int n2, int n)
{
    if (n > strl(src) || n == 0){
        n = strl(src);
    }
    while (n2 < n){
        dest[n2] = src[n2];
        n2++;
    }
    return dest;
}
