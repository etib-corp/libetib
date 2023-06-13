/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** main
*/

#include "Window2d.hpp"
#include "Entity2d.hpp"

int main(void)
{
    Window2d *window = new Window2d();
    Entity2d entity;
    while (window->isOpen()) {
        while (window->window.pollEvent(window->event)) {
            if (window->event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        window->display();
    }
    return 0;
}
