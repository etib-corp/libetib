/*
** EPITECH PROJECT, 2023
** libetib
** File description:
** LinkedList
*/

#include "LinkedList.hpp"

LinkedList::LinkedList(constructor_t constructor, destructor_t destructor, printer_t printer)
{
    LinkedList::head = nullptr;
    LinkedList::tail = nullptr;
    LinkedList::size = 0;
    LinkedList::constructor = constructor;
    LinkedList::destructor = destructor;
    LinkedList::printer = printer;
}

LinkedList::~LinkedList()
{
}

bool LinkedList::isEmpty(void)
{
    if (this->size == 0)
        return true;
    return false;
}

bool LinkedList::pushAt(int index, ...)
{
    va_list args;
    int abs_index = ABS(index);
    va_start(args, index);
    if (abs_index > this->size)
        return false;
    if (index == 0) {
        if (!this->pushFront(&args))
            return false;
        this->size++;
        return true;
    }
    Node *tmp = (index > 0) ? this->head : this->tail;
    for (int i = 0; i < abs_index; i++)
        tmp = TTT(tmp, index);
    if (!tmp->pushBack(&args))
        return false;
    this->size++;
    va_end(args);
    return true;
}

bool LinkedList::pushBack(va_list *ap)
{

    if (this->isEmpty()) {
        this->head = new Node(ap, this->constructor, this->destructor, this->printer);
        this->tail = this->head;
    } else {
        if (!this->tail->pushBack(ap))
            return false;
        this->tail = this->tail->next;
    }

    this->size++;
    return true;
}

bool LinkedList::pushFront(va_list *ap)
{


    if (this->isEmpty()) {
        this->head = new Node(ap, this->constructor, this->destructor, this->printer);
        this->tail = this->head;
    } else {
        this->head->pushFront(ap);
        this->head = this->head->prev;
    }
    this->size++;
    return true;
}

bool LinkedList::popBack(void)
{
    if (this->isEmpty())
        return false;
    if (this->head == tail) {
        delete head;
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        Node *tmp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        tmp->~Node();
    }
    this->size--;
    return true;
}

bool LinkedList::popFront(void)
{
    if (this->isEmpty())
        return false;
    if (this->head == tail) {
        delete head;
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        Node *tmp = this->head;
        this->head = this->head->next;
        this->head->prev = nullptr;
        tmp->~Node();
    }
    this->size--;
    return true;
}

bool LinkedList::insert(int index, ...)
{
    Node *tmp = this->head;
    va_list args;
    va_start(args, index);
    if (index < 0 || index > this->size)
        return false;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    tmp->pushBack(&args);
    va_end(args);
    this->size++;
    return true;
}

void LinkedList::printNodes(void)
{
    Node *tmp = this->head;
    while (tmp != nullptr) {
        tmp->print();
        tmp = tmp->next;
    }
}
