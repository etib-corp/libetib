/*
** EPITECH PROJECT, 2023
** libetib
** File description:
** main
*/
#include "LinkedList.hpp"
#include <list>

void *test(va_list *ap)
{
    return va_arg(*ap, char *);
}

void test_destroy(void *data)
{
    free(data);
}

void test_print(void *data)
{
    printf("%s\n", (char *)data);
}

int main(void)
{
    // char with shared_ptr
    // std::shared_ptr<LinkedList> list = std::make_shared<LinkedList>(test, test_destroy, test_print);
    LinkedList *list = new LinkedList(test, test_destroy, test_print);
    printf("%d\n", list->pushAt(-1, "node1"));
    printf("%d\n", list->pushAt(-1, "node2"));
    printf("%d\n", list->pushAt(-1, "node3"));
    printf("%d\n", list->pushAt(-1, "node4"));
    printf("%d\n", list->pushAt(0, "node0"));
    printf("%d\n", list->pushAt(0, "node-1"));
    list->printNodes();
    return 0;
}