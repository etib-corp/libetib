/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** my_is_digit
*/

#include "my.h"

bool my_is_digit(char c)
{
    if ((c < '0' || c > '9') && c != '-')
        return false;
    return true;
}

bool my_str_is_digit(char *str)
{
    if (str == NULL)
        return false;
    for (int i = 0; str[i]; i++) {
        if (!my_is_digit(str[i]))
            return false;
    }
    return true;
}
