/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** window
*/


#include "window.h"

Window::Window()
{
}

Window::~Window()
{
}

void Window::createWindow(void)
{
    window.create(sf::VideoMode(800, 600), "My window", sf::Style::Default);
}

void Window::displayWindow(void)
{
    window.display();
}

void Window::destroyWindow(void)
{
    window.close();
}

bool Window::isOpen(void)
{
    return window.isOpen();
}

void Window::clearWindow(void)
{
    window.clear();
}
