/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-julien.ferdinand
** File description:
** swap_endian
*/

#include "my.h"

unsigned int swap_endian(int n)
{
    char tmp = 0;
    union int_endian new = {.n = n};

    tmp = new.bytes[0];
    new.bytes[0] = new.bytes[3];
    new.bytes[3] = tmp;

    tmp = new.bytes[1];
    new.bytes[1] = new.bytes[2];
    new.bytes[2] = tmp;

    return new.n;
}

unsigned short short_swap_endian(unsigned short n)
{
    char tmp = 0;
    union short_endian new = {.n = n};

    tmp = new.bytes[0];
    new.bytes[0] = new.bytes[1];
    new.bytes[1] = tmp;

    return new.n;
}
