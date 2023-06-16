/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** window
*/
#include "Window2d.hpp"

Window2d::Window2d(void)
{
    this->window.create(sf::VideoMode(800, 600), "My window", sf::Style::Default);
    this->event = sf::Event();
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

void Window2d::addEvent(sf::Event::EventType type, std::function<void(void)> func)
{
    this->events.addEvent(type, func);
}

void Window2d::addKey(sf::Keyboard::Key key, std::function<void(void)> func)
{
    this->events.addKey(key, func);
}

void Window2d::addMouse(sf::Mouse::Button button, std::function<void(void)> func)
{
    this->events.addMouse(button, func);
}

void Window2d::addJoystickAxis(sf::Joystick::Axis axis, std::function<void(void)> func)
{
    this->events.addJoystickAxis(axis, func);
}

void Window2d::addJoystickButton(unsigned int button, std::function<void(void)> func)
{
    this->events.addJoystickButton(button, func);
}

void Window2d::destroyEvent(sf::Event::EventType type)
{
    this->events.destroyEvent(type);
}

void Window2d::destroyKey(sf::Keyboard::Key key)
{
    this->events.destroyKey(key);
}

void Window2d::destroyMouse(sf::Mouse::Button button)
{
    this->events.destroyMouse(button);
}

void Window2d::destroyJoystickAxis(sf::Joystick::Axis axis)
{
    this->events.destroyJoystickAxis(axis);
}

void Window2d::destroyJoystickButton(unsigned int button)
{
    this->events.destroyJoystickButton(button);
}

void Window2d::manageEvent(void)
{
    while (this->window.pollEvent(this->event))
        this->events.manageEvent(this->event);
}