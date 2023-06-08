/*
** EPITECH PROJECT, 2022
** miniprintf.h
** File description:
** .h of miniprintf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <unistd.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <wchar.h>

typedef union data_s {
    long long *llp;
    long long unsigned llu;
    signed char sc;
    unsigned char uc;
    signed char *scp;
    intmax_t im_t;
    intmax_t *im_tp;
    uintmax_t uim_t;
    long *lp;
    long double ld;
    size_t *sp;
    size_t s;
    ssize_t ss;
    long l;
    ptrdiff_t ptr;
    ptrdiff_t *ptrp;
    short sh;
    short unsigned shu;
    short *shp;
    wint_t wt;
    char *str;
    wchar_t *wc;
    long unsigned lu;
    long long ll;
    int base;
    unsigned int baseu;
    int *basep;
    double float_d;
} data_t;

typedef struct length {
    char l_type;
    int v_type;
} length_t;

typedef struct args {
    int zero;
    int mins;
    int sharp;
    int space;
    int plus;
    int width;
    int precision;
    int length;
    char conversion;
} args_t;

typedef struct parser {
    int index;
    int count;
    char const *restrict format;
    va_list ap;
} parser_t;

typedef struct convert {
    char flag_type;
    int (*exec)(va_list *, args_t *, parser_t *, int fd);
} convert_t;

typedef struct flags_s {
    char flag;
    char conv;
    int (*len)(void *);
} flags_printf_t;

int skip_lib(const char c, const char *tokens);
int my_binflags(args_t *arg, int len, int fd);
int my_xflags(args_t *arg, int len, int fd);
int my_charflags(args_t *arg, int len, int fd);
int my_intflags(args_t *arg, int len, int fd);
int my_octflags(args_t *arg, int len, int fd);
int my_floatflags(args_t *arg, int len, int fd);
int my_putsame_char(int r, char c, int fd);
int my_length_of_c(args_t *arg, int nb);
long double my_length_of_all(args_t *arg, long double nb);
void *my_length_of_n(args_t *arg, long long *nb);
size_t my_length_ic(args_t *arg, size_t nb);
void update(args_t *arg, char c);
int my_lennbr_base(size_t value, char const *base);
int my_flags(args_t *arg, int len, int fd);
int my_endflags(args_t *arg, int len, int count, int fd);
long long my_length_of_di(args_t *arg, long long nb);
void length(parser_t *pr, args_t *arg);
int precision(parser_t *pr);
void conversion(char c, args_t *arg, parser_t *pr, int fd);
void flags(parser_t *pr, args_t *arg);
int my_getnbr(char const *str);
int my_putnbr_base(size_t nbr, char const *base, int fd);
int my_showstr(char const *str, int fd);
int my_printf(char const *restrict format, ...);
int my_dprintf(int fd, const char *restrict format, ...);
int my_vdprintf(int fd, const char *restrict format, va_list *ap);
int my_putchar_printf(char c, int fd);
int my_put_nbr_printf(long long nb, int fd);
int my_putstr_printf(char const *str, int s, int fd);
int my_printstr(va_list *list, args_t *arg, parser_t *pr, int fd);
int my_strlen(char const *str);
int my_put_float(double nbr, int j, int fd);
int my_printusnbr(va_list *ap, args_t *arg, parser_t *pr, int fd);
int my_printnbr_octal(va_list *ap, args_t *arg, parser_t *pr, int fd);
int my_printnbr_hexa(va_list *ap, args_t *arg, parser_t *pr, int fd);
int my_printnbr_mhexa(va_list *ap, args_t *arg, parser_t *pr, int fd);
int my_printmodulo(int fd);
int my_printchar(va_list *list, args_t *arg, parser_t *pr, int fd);
int my_printnbr(va_list *list, args_t *arg, parser_t *pr, int fd);
int my_printfloat(va_list *list, args_t *arg, parser_t *pr, int fd);
int my_printnbr_wtn(va_list *list, args_t *arg, parser_t *pr, int fd);
int my_printptr(va_list *list, args_t *arg, parser_t *pr, int fd);
int my_printnbr_bin(va_list *list, args_t *arg, parser_t *pr, int fd);
int my_showva(va_list *list, args_t *arg, parser_t *pr, int fd);
size_t my_lennbr(size_t nb);

#endif
