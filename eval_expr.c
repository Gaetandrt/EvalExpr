/*
** EPITECH PROJECT, 2021
** eval_expr.c
** File description:
** all_calculs
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "./include/my.h"

bool is_digit(char c);

int parse_expression(char **str);

int number(char **str);

int parse_digit(char **str)
{
    int result = 0;

    if (is_digit(**str) || **str == '-') {
        result = number(str);
    }
    return (result);
}

int parse_factor(char **str)
{
    int result = 0;
    if (**str == '(') {
        *str += 1;
        result = parse_expression(str);
        *str += 1;
        return (result);
    } else {
        return (parse_digit(str));
    }
}

int parse_term(char **str)
{
    int result = parse_factor(str);

    while (true) {

        if (**str == '/') {
            *str += 1;
            result /= parse_factor(str);
        }
        if (**str == '*') {
            *str += 1;
            result *= parse_factor(str);
        } else if (**str == '%') {
            *str += 1;
            result %= parse_factor(str);
        } else {
            break;
        }
    }
    return (result);
}

int parse_expression(char **str)
{
    int result = parse_term(str);

    while (true) {
        if (**str == '+') {
            *str += 1;
            result += parse_term(str);
        } else if (**str == '-') {
            *str += 1;
            result -= parse_term(str);
        } else
            break;
    }
    return (result);
}
