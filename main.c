/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main_func
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "./include/my.h"

bool is_digit(char c);

int parse_expression(char **str);

int parse_digit(char **str);

int eval_expr(char const *str)
{
    return (parse_expression((char **)&str));
}

int main (int ac , char ** av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84) ;
}
