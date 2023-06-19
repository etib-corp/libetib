/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** main
*/

/* DO NOT MOVE ALL INCLUDE INSIDE OF SFML_INCLUDE SINCE THIS MAIN ISN'T FOR RELEASE */
#include "Event2d.hpp"
#include "Window2d.hpp"
#include "Entity2d.hpp"
#include "JSONParser.hpp"

void addAllEvent(Window2d *&window)
{
    window->addEvent(sf::Event::Closed, [&window]() {
        window->close();
    });
    window->addKey(sf::Keyboard::Escape, [&window]() {
        window->close();
    });
}

int main(void)
{
    Window2d *window = new Window2d();
    addAllEvent(window);
    while (window->isOpen()) {
        window->manageEvent();
        window->clear(sf::Color::Black);
        window->display();
    }
    return 0;
}
