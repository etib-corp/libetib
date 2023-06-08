/*
** EPITECH PROJECT, 2022
** B-MUL-100-RUN-1-1-myradar-julien.ferdinand
** File description:
** aux
*/
#include "my.h"

bool skip(char c, char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (c == s[i])
            return true;
    return false;
}

int my_word_count(char *str, char *s)
{
    int i = 1;
    int j = 0;
    if (str == NULL || s == NULL)
        return 0;
    while (str[i] != '\0')
        if (!skip_lib(str[i - 1], s) && skip_lib(str[i], s)) {
            i++;
            j++;
        } else
            i++;
    return j + 1;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (dest == NULL || n <= 0)
        return NULL;
    for (i = 0; src && src[i] && i < n; i++)
        dest[i] = src[i];
    for ( ; i < n; i++)
        dest[i] = '\0';
    return dest;
}

char **my_str_to_word_array(char *str, char *s)
{
    int w = my_word_count(str, s);
    char **array = my_calloc(sizeof(char *), (w + 1));
    int i = 0;
    int j = 0;
    int pos = 0;
    if (!array)
        return NULL;
    if (!str)
        return NULL;
    while (str[i] != '\0' && j < w) {
        if (skip_lib(str[i], s)) {
            i++;
            continue;
        } for (pos = 0; str[i] != '\0' && !skip(str[i], s); i++, pos++);
        array[j] = my_calloc(sizeof(char), (pos + 1));
        array[j] = my_strncpy(array[j], str + i++ - pos, pos);
        j++;
    }
    array[j] = NULL;
    return array;
}
