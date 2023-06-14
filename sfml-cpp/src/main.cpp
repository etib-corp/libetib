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
    std::function<void(va_list)> fptr = std::bind(&Window2d::close, window);
    bool (*c)(sf::Event) = [](sf::Event event) {
        if (event.type == sf::Event::Closed)
            return true;
        return false;
    };
    window->addEvent(c, fptr);
    while (window->isOpen()) {
        window->manageEvent(window);
        window->clear(sf::Color::Red);
        window->display();
    }
    return 0;
}
