/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** window
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include "sfml_include.hpp"

class Window {
    private:
    public:
        sf::Event event;
        sf::RenderWindow window;
        Window();
        ~Window();
        bool isOpen(void);
        void displayWindow(void);
        void clearWindow(void);
        void destroyWindow(void);
};

#endif /* !WINDOW_H_ */
