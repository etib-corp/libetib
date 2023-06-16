/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** main
*/
#include "Event2d.hpp"
#include "Window2d.hpp"
#include "Entity2d.hpp"

void addAllEvent(Window2d *&window)
{
    window->addEvent(sf::Event::Closed, [&window]() {
        window->close();
    });
    window->addKey(sf::Keyboard::Escape, [&window]() {
        window->close();
    });
    window->addMouse(sf::Mouse::Left, [&window]() {
        window->close();
    });
    window->addKey(sf::Keyboard::Up, [&window]() {
        std::cout << "Up" << std::endl;
    });
}

int main(void)
{
    std::shared_ptr<Window2d> window = std::make_shared<Window2d>();
    auto PTR = window.get();
    addAllEvent(PTR);
    while (window->isOpen()) {
        window->manageEvent();
        window->clear(sf::Color::Red);
        window->display();
    }
    return 0;
}
