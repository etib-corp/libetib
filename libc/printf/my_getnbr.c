/*
** EPITECH PROJECT, 2022
** oui
** File description:
** non
*/
#include "my_printf.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int res = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res * neg;
}
