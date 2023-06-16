/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** window
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include "sfml_include.hpp"

#ifndef EVENT2D_HPP_
#include "Event2d.hpp"
#endif /* !EVENT2D_HPP_ */


class Window2d {
    private:
    public:
        sf::Event event;
        sf::RenderWindow window;
        Event2d events;
        Window2d();
        ~Window2d();
        bool isOpen(void);
        void display(void);
        void clear(sf::Color color = sf::Color::Black);
        void close(void);
        void manageEvent(...);
        void setFramerateLimit(unsigned int limit);
        bool addEvent(std::function<bool(sf::Event)> condition, std::function<void(va_list)> ptr = nullptr, std::string name = "");
        bool removeEvent(std::string name);
        bool removeAllEvents(void);
};


#endif /* !WINDOW_H_ */

/*
manageEvent method that will use the event attribute of the window and a list of struct that will contain a pointer to a function and a sf::Event::EventType.
*/