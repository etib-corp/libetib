/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** node
*/

#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include <memory>
#include <utility>

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define TTT(node, index) (index > 0) ? node->next : node->prev

typedef void (*printer_t)(void *);
typedef void *(*constructor_t)(va_list *);
typedef void (*destructor_t)(void *);

class Node {
    public:
        Node *next;
        Node *prev;
        void *data;
        constructor_t constructor;
        destructor_t destructor;
        printer_t printer;
        Node(va_list *ap, constructor_t constructor, destructor_t destructor, printer_t printer);
        ~Node();
        bool pushBack(va_list *ap);
        bool pushFront(va_list *ap);
        void print(void);
};


#endif /* !NODE_HPP_ */
