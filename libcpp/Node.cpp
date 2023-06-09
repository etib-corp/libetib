/*
** EPITECH PROJECT, 2023
** libetib
** File description:
** Node
*/

#include "Node.hpp"

Node::Node(va_list *ap, constructor_t constructor, destructor_t destructor, printer_t printer)
{
    Node::next = nullptr;
    Node::prev = nullptr;
    Node::constructor = constructor;
    Node::destructor = destructor;
    Node::printer = printer;
    Node::data = constructor(ap);
}

Node::~Node()
{
    destructor(Node::data);
}

bool Node::pushBack(va_list *ap)
{
    Node *newNode = new Node(ap, this->constructor, this->destructor, this->printer);
    newNode->prev = this;
    newNode->next = this->next;
    this->next = newNode;
    return true;
}

bool Node::pushFront(va_list *ap)
{
    Node *newNode = new Node(ap, this->constructor, this->destructor, this->printer);
    newNode->next = this;
    newNode->prev = this->prev;
    this->prev = newNode;
    return true;
}

void Node::print(void)
{
    this->printer(this->data);
}