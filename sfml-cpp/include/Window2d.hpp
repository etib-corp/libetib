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
        void clear(void);
        void close(void);
        
};

#endif /* !WINDOW_H_ */

/*
manageEvent method that will use the event attribute of the window and a list of struct that will contain a pointer to a function and a sf::Event::EventType.
*/