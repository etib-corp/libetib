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
    this->event = sf::Event();
    this->events = Event2d();
}

Window2d::~Window2d()
{
}

bool Window2d::isOpen(void)
{
    return this->window.isOpen();
}

void Window2d::display(void)
{
    this->window.display();
}

void Window2d::close(void)
{
    this->window.close();
}

void Window2d::clear(sf::Color color)
{
    this->window.clear(color);
}

void Window2d::setFramerateLimit(unsigned int limit)
{
    this->window.setFramerateLimit(limit);
}

void Window2d::manageEvent(...)
{
    va_list ap;
    va_start(ap, this);
    this->events.manageEvent(ap);
    va_end(ap);
}

bool Window2d::addEvent(std::function<bool(sf::Event)> condition, std::function<void(va_list)> ptr, std::string name)
{
    return this->events.addEvent(condition, ptr, name);
}

bool Window2d::removeEvent(std::string name)
{
    return this->events.removeEvent(name);
}

bool Window2d::removeAllEvents(void)
{
    return this->events.removeAllEvents();
}
