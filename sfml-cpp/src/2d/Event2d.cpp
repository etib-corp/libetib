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

bool Event2d::addEvent(std::function<bool(sf::Event)> condition, std::function<void(va_list)> ptr, std::string name)
{
    event_t event = {condition, ptr, name};
    this->events.push_back(event);
    return true;
}

bool Event2d::removeEvent(std::string name)
{
    for (auto it = this->events.begin(); it != this->events.end(); it++) {
        if (it->name == name) {
            this->events.erase(it);
            return true;
        }
    }
    return false;
}

bool Event2d::removeAllEvents(void)
{
    this->events.clear();
    return true;
}

void Event2d::manageEvent(va_list ap)
/* first va_list arg has to be Window2d **/
{
    va_list tmp;
    va_copy(tmp, ap);
    bool end = false;
    Window2d *window = va_arg(tmp, Window2d *);
    while (window->window.pollEvent(window->event)) {
        for (auto it = this->events.begin(); (end = (it != this->events.end())); it++) {
            if (it->condition(window->event)) {
                va_copy(tmp, ap);
                it->fptr(tmp);
                break;
            }
        #ifdef DEBUG
        if (end) {
            std::cout << "Event " << 0 << " not found" << std::endl;
        }
        #endif /* DEBUG */
        }
    }
}