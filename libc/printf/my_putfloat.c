/*
** EPITECH PROJECT, 2022
** my_putfloat.c
** File description:
** puts floats
*/
#include "my_printf.h"

static double rounded(double nbr, int j)
{
    int i = 0;
    for (; i < j; i++)
        nbr *= 10;
    if ((nbr * 10 - (int)nbr * 10) >= 5)
        nbr += 1;
    for (; i > 0; i--)
        nbr /= 10;
    return nbr;
}

int my_put_float(double nbr, int j, int fd)
{
    int i = 0;
    long double ent = (long long)nbr;
    int k = 1;

    nbr = rounded(nbr, j);
    i += my_put_nbr_printf(ent, fd);
    if (j == -1)
        return i;
    i += my_putchar_printf('.', fd);
    nbr -= ent;
    while (k <= j) {
        i += my_put_nbr_printf((nbr - (int)nbr) * 10, fd);
        nbr = nbr * 10;
        k++;
    }
    return i;
}

int my_lenfloat(long double nb,  int j)
{
    int i = 0;
    long double ent = (long long)nb;

    i += my_lennbr(ent);
    i++;
    i += j;
    return i;
}

int my_printfloat(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    int count = 0;
    (void)pr;
    long double value = va_arg(*list, double);
    int len = my_lenfloat(value, arg->precision);
    value = my_length_of_all(arg, value);

    if (arg->width > 0) {
        len += 2;
        count += 2;
    }
    count += my_flags(arg, len, fd);
    count += my_put_float(value, arg->precision, fd);
    count += my_endflags(arg, len, count, fd);
    if (arg->width > 0)
        return arg->width;
    return count - len + 2;
}
