/*
** EPITECH PROJECT, 2022
** flags_extra.c
** File description:
** all functions for my_flags.c
*/

#include "my_printf.h"

int my_xflags(args_t *arg, int len, int fd)
{
    int count = 0;

    if (arg->width < arg->precision)
        arg->width = arg->precision;
    if (arg->sharp > 0) {
        if (arg->mins == 0 && arg->zero == 0)
            count += my_putsame_char(arg->width - len - 2, ' ', fd);
        if (arg->conversion == 'x')
            count += my_putstr_printf("0x", 2, fd);
        else
            count += my_putstr_printf("0X", 2, fd);
    } else {
        if (arg->width == arg->precision)
            return my_putsame_char(arg->width - count - len, '0', fd);
        if (arg->mins == 0 && arg->zero == 0)
            return my_putsame_char(arg->width - count - len, ' ', fd);
    }
    if (arg->zero > 0 || arg->width == arg->precision)
        return my_putsame_char(arg->width - count - len, '0', fd);
    return count;
}

int my_floatflags(args_t *arg, int len, int fd)
{
    if (arg->sharp > 0 && arg->mins == 0) {
        if (arg->precision < 0 && arg->zero > 0)
            return my_putsame_char(arg->width - len + 1, ' ', fd);
        if (arg->precision < 0 && arg->zero == 0)
            return my_putsame_char(arg->width - len + 1, '0', fd);
    }
    if (arg->sharp == 0 && arg->mins == 0) {
        if (arg->zero == 0)
            return my_putsame_char(arg->width - len + 2, ' ', fd);
        if (arg->zero > 0)
            return my_putsame_char(arg->width - len, '0', fd);
    } else {
        return 0;
    }
    return 0;
}

int my_octflags(args_t *arg, int len, int fd)
{
    int count = 0;

    if (arg->width < arg->precision)
        arg->width = arg->precision;
    if (arg->sharp > 0) {
        if (arg->mins == 0 && arg->zero == 0)
            count += my_putsame_char(arg->width - len - 1, ' ', fd);
        count += my_putchar_printf('0', fd);
    } else {
        if (arg->mins == 0 && arg->zero == 0)
            return my_putsame_char(arg->width - count - len, ' ', fd);
    }
    if (arg->zero > 0 || arg->width == arg->precision)
        return my_putsame_char(arg->width - count - len, '0', fd);
    return count;
}

int my_intflags(args_t *arg, int len, int fd)
{
    int count = 0;

    if (arg->width < arg->precision)
        arg->width = arg->precision;
    if (arg->mins == 0 && arg->zero == 0)
            return my_putsame_char(arg->width - len, ' ', fd);
    count += len;
    if (arg->zero > 0 || arg->width == arg->precision)
        return my_putsame_char(arg->width - count, '0', fd);
    return count;
}

int my_charflags(args_t *arg, int len, int fd)
{
    int count = 0;

    if (arg->mins == 0 && arg->zero == 0)
        return my_putsame_char(arg->width - len, ' ', fd);
    return count;
}
