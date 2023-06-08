/*
** EPITECH PROJECT, 2022
** my_flags.c
** File description:
** modify the output of a function
*/
#include "my_printf.h"

int my_putsame_char(int r, char c, int fd)
{
    int i = 1;

    if (r <= 0)
        return 0;
    while (i <= r)
        i += my_putchar_printf(c, fd);
    return i;
}

int my_binflags(args_t *arg, int len, int fd)
{
    int count = 0;

    if (arg->width < arg->precision)
        arg->width = arg->precision;
    if (arg->sharp > 0) {
        if (arg->mins == 0 && arg->zero == 0)
            count += my_putsame_char(arg->width - len - 2, ' ', fd);
        if (arg->conversion == 'b')
            count += my_putstr_printf("0b", 2, fd);
        else
            count += my_putstr_printf("0B", 2, fd);
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

int my_flags(args_t *arg, int len, int fd)
{
    int count = 0;

    if (skip_lib(arg->conversion, "xX") != 0)
        count += my_xflags(arg, len, fd);
    if (skip_lib(arg->conversion, "aAeEfFgG") != 0)
        count += my_floatflags(arg, len, fd);
    if (skip_lib(arg->conversion, "bB") != 0)
        count += my_binflags(arg, len, fd);
    if (arg->conversion == 'o')
        count += my_octflags(arg, len, fd);
    if (skip_lib(arg->conversion, "diu") != 0)
        count += my_intflags(arg, len, fd);
    if (skip_lib(arg->conversion, "cs") != 0)
        count += my_charflags(arg, len, fd);
    return count;
}

int my_endflags(args_t *arg, int len, int count, int fd)
{
    (void)len;
    if (skip_lib(arg->conversion, "aAeEfFgG") != 0) {
        if (arg->sharp > 0 && arg->precision < 0)
            count += my_putchar_printf('.', fd);
        count -= 2;
    }
    if (arg->mins > 0) {
        if (arg->width > count && skip_lib(arg->conversion, "di") == 0)
            return my_putsame_char(arg->width - count, ' ', fd);
        else
            return my_putsame_char(arg->width - len, ' ', fd);
    }
    return count;
}
