/*
** EPITECH PROJECT, 2021
** number.c
** File description:
** number **str
*/

#include <stdbool.h>
#include <string.h>
#include "./include/my.h"

int parse_expression(char **str);

int number(char **str)
{
    int signe = 1;
    int resultat = 0;

    while ('-' == **str) {
        signe = signe * (-1);
        *str += 1;
    }
    if (**str == '(') {
        *str += 1;
        resultat = parse_expression(str);
        *str += 1;
    }
    while (is_digit(**str)) {
        resultat = resultat * 10 + **str - '0';
        *str += 1;
    }
    return (resultat * signe);
}
