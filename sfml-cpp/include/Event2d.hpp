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

template<typename... T>
struct event_s {
    std::function<bool(sf::Event, T...)> condition;
    std::function<void(va_list)> fptr;
    std::string name;
};

class Event2d {
    private:
        std::list<event_s<int>> events;
    public:
        Event2d();
        ~Event2d();
        bool addEvent(std::function<bool(sf::Event)> condition = nullptr , std::function<void(va_list)> fptr = nullptr, std::string name = "");
        bool removeEvent(std::string name);
        bool removeAllEvents(void);
        void manageEvent(va_list ap);
};

#endif /* !EVENT2D_HPP_ */
