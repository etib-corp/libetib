/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** main
*/

#include "window.h"
#include "entity.hpp"

int main()
{
    Window window;
    Entity entity;
    window.createWindow();
    while (window.isOpen()) {
        while (window.window.pollEvent(window.event)) {
            if (window.event.type == sf::Event::Closed)
                window.destroyWindow();
        }
        window.clearWindow();
        window.displayWindow();
    }
    return 0;
}
