/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Event2d
*/

#ifndef EVENT2D_HPP_
#define EVENT2D_HPP_

#ifndef WINDOW_H_
#include "Window2d.hpp"
#endif /* !WINDOW_H_ */

#include "sfml_include.hpp"
#include <list>
#include <stdarg.h>

typedef struct event_s {
    sf::Event::EventType type;
    void (*fptr)(va_list);
} event_t;

class Event2d {
    private:
        std::list<event_t> events;
    public:
        Event2d();
        ~Event2d();
        void addEvent(sf::Event::EventType type, void (*fptr)(va_list));
        void removeEvent(sf::Event::EventType type);
        void removeAllEvents(void);
        void manageEvent(...);
};

#endif /* !EVENT2D_HPP_ */
