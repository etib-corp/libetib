/*
** EPITECH PROJECT, 2022
** oui
** File description:
** non
*/
#include "my_printf.h"

static int conv_octal(char c, int fd)
{
    int count = 0;

    if (c < 100 && c > 7)
        count += my_putchar_printf('0', fd);
    if (c <= 7)
        count += my_putstr_printf("00", 2, fd);
    count += my_putnbr_base(c, "01234567", fd);
    return count;
}

int my_showstr(char const *str, int fd)
{
    int i = 0;
    int stock = 0;

    while (str[i] != '\0') {
        if (str[i] >= ' ' && str[i] <= '~')
            stock += my_putchar_printf(str[i], fd);
        else {
            stock += my_putchar_printf('\\', fd);
            stock += conv_octal(str[i], fd);
        }
        i++;
    }
    return stock;
}

int my_showva(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    char *value = va_arg(*list, char *);
    int len = my_strlen(value);
    int count = 0;

    if (arg->precision > 0 && arg->precision < len)
        len = arg->precision;
    count += my_flags(arg, len, fd);
    count += my_showstr(value, fd);
    count += my_endflags(arg, len, count, fd);
    return count;
}
