/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** main
*/

#include "Window.hpp"
#include "Entity.hpp"

int main(void)
{
    Window *window = new Window();
    Entity entity;
    while (window->isOpen()) {
        while (window->window.pollEvent(window->event)) {
            if (window->event.type == sf::Event::Closed)
                window->destroyWindow();
        }
        window->clearWindow();
        window->displayWindow();
    }
    return 0;
}
