/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** window
*/


#include "Window2d.hpp"

Window2d::Window2d()
{
    this->window.create(sf::VideoMode(800, 600), "My window", sf::Style::Default);
}

Window2d::~Window2d()
{
}

void Window2d::display(void)
{
    this->window.display();
}

void Window2d::close(void)
{
    this->window.close();
}

bool Window2d::isOpen(void)
{
    return this->window.isOpen();
}

void Window2d::clear(void)
{
    this->window.clear();
}
