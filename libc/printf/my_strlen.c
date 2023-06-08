/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** str len
*/
#include "my_printf.h"

int my_strlen(char const *str)
{
    if (str == NULL)
        return 0;
    int i = 0;
    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

size_t my_lennbr(size_t nb)
{
    int i = 0;
    while (nb /= 10)
        i++;
    return ++i;
}

int my_lennbr_base(size_t nb, char const *src)
{
    int i = 0;
    size_t d = 1;
    size_t len = my_strlen(src);

    while (nb / d >= len) {
        d = d * len;
        i++;
    }
    return i + 1;
}
