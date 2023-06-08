/*
** EPITECH PROJECT, 2022
** my_outmodifier.c
** File description:
** modify the output of a function
*/

#include "my_printf.h"

long double my_length_of_all(args_t *arg, long double nb)
{
    data_t data;

    data.ld = nb;
    if (arg->length == 3)
        return data.ld;
    return data.float_d = nb;
}

int my_length_of_c(args_t *arg, int nb)
{
    data_t data;

    data.base = nb;
    if (arg->length == 1)
        return data.wt;
    return data.base;
}

size_t my_length_ic(args_t *arg, size_t nb)
{
    data_t data;

    data.llu = nb;
    if (arg->length == 1)
        return data.lu;
    if (arg->length == 2)
        return data.shu;
    if (arg->length == 4)
        return data.uim_t;
    if (arg->length == 5)
        return data.ss;
    if (arg->length == 6)
        return data.ptr;
    if (arg->length == 7)
        return data.llu;
    if (arg->length == 8)
        return data.uc;
    return data.baseu;
}

void *my_length_of_n(args_t *arg, long long *nb)
{
    data_t data;

    data.llp = nb;
    if (arg->length == 1)
        return data.lp;
    if (arg->length == 2)
        return data.shp;
    if (arg->length == 4)
        return data.im_tp;
    if (arg->length == 5)
        return data.sp;
    if (arg->length == 6)
        return data.ptrp;
    if (arg->length == 7)
        return data.llp;
    if (arg->length == 8)
        return data.scp;
    return data.basep;
}

long long my_length_of_di(args_t *arg, long long nb)
{
    data_t data;

    data.ll = nb;
    if (arg->length == 1)
        return data.l;
    if (arg->length == 2)
        return data.sh;
    if (arg->length == 4)
        return data.im_t;
    if (arg->length == 5)
        return data.s;
    if (arg->length == 6)
        return data.ptr;
    if (arg->length == 7 || arg->length == 9)
        return data.ll;
    if (arg->length == 8)
        return data.sc;
    return data.base;
}
