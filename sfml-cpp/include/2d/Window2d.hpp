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
        Window2d(void);
        ~Window2d();
        sf::Event event;
        sf::RenderWindow window;
        Event2d events;
        bool isOpen(void);
        void display(void);
        void clear(sf::Color color = sf::Color::Black);
        void close(void);
        void setFramerateLimit(unsigned int limit);
        void addEvent(sf::Event::EventType type, std::function<void(void)> func);
        void addKey(sf::Keyboard::Key key, std::function<void(void)> func);
        void addMouse(sf::Mouse::Button button, std::function<void(void)> func);
        void addJoystickAxis(sf::Joystick::Axis axis, std::function<void(void)> func);
        void addJoystickButton(unsigned int button, std::function<void(void)> func);
        void destroyEvent(sf::Event::EventType type);
        void destroyKey(sf::Keyboard::Key key);
        void destroyMouse(sf::Mouse::Button button);
        void destroyJoystickAxis(sf::Joystick::Axis axis);
        void destroyJoystickButton(unsigned int button);
        void manageEvent(void);
};


#endif /* !WINDOW_H_ */

/*
manageEvent method that will use the event attribute of the window and a list of struct that will contain a pointer to a function and a sf::Event::EventType.
*/