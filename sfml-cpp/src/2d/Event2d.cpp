/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Event2d
*/

#include "Window2d.hpp"

Event2d::Event2d()
{
    this->events = std::list<event_t>();

}

Event2d::~Event2d()
{
}

void Event2d::addEvent(sf::Event::EventType type, void (*ptr)(va_list))
{
    event_t event = {type, ptr};
    this->events.push_back(event);
}

void Event2d::removeEvent(sf::Event::EventType type)
{
    for (auto it = this->events.begin(); it != this->events.end(); it++) {
        if (it->type == type)
            this->events.erase(it);
    }
}

void Event2d::removeAllEvents(void)
{
    this->events.clear();
}

void Event2d::manageEvent(...)
/* first va_list arg has to be Window2d **/
{
    va_list ap;
    va_start(ap, this);
    Window2d *window = va_arg(ap, Window2d *);
    while (window->window.pollEvent(window->event)) {
        for (auto it = this->events.begin(); it != this->events.end(); it++) {
            if (it->type == window->event.type)
                it->fptr(ap);
        }
    }
    va_end(ap);
}