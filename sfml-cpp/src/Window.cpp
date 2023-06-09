/*
** ETIB PROJECT, 2023
** cpp
** File description:
** window
*/


#include "Window.hpp"

Window::Window()
{
    this->window.create(sf::VideoMode(800, 600), "My window", sf::Style::Default);
}

Window::~Window()
{
}

void Window::displayWindow(void)
{
    this->window.display();
}

void Window::destroyWindow(void)
{
    this->window.close();
}

bool Window::isOpen(void)
{
    return this->window.isOpen();
}

void Window::clearWindow(void)
{
    this->window.clear();
}