/*
** EPITECH PROJECT, 2023
** libcpp
** File description:
** linkedlist
*/

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include "Node.hpp"
#include <cstdarg>

typedef void (*printer_t)(void *);
typedef void *(*constructor_t)(va_list *);
typedef void (*destructor_t)(void *);

class LinkedList {
    public:
        Node *head;
        Node *tail;
        int size;
        LinkedList(constructor_t constructor, destructor_t destructor, printer_t printer);
        ~LinkedList(void);
        constructor_t constructor;
        destructor_t destructor;
        printer_t printer;

        bool pushBack(va_list *ap);
        bool pushFront(va_list *ap);
        bool pushAt(int index, ...);

        bool popBack(void);
        bool popFront(void);
        bool insert(int index, ...);
        void printNodes(void);
        // void erase(int index);
        // void clear(void);
        // int getSize(void);
        // int at(int index);
        bool isEmpty(void);
};


#endif /* !LINKEDLIST_HPP_ */
