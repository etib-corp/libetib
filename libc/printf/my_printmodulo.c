/*
** EPITECH PROJECT, 2022
** oui
** File description:
** non
*/

#include "my_printf.h"

int my_printmodulo(int fd)
{
    int count = 0;

    count += my_putchar_printf('%', fd);
    return count;
}
