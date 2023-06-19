/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Event2d
*/
#include "Event2d.hpp"
#include "sfml_include.hpp"

Event2d::Event2d()
{
}

Event2d::~Event2d()
{
}

void Event2d::addEvent(sf::Event::EventType type, std::function<void(void)> func)
{
    this->EventType[type] = func;
}

void Event2d::addKey(sf::Keyboard::Key key, std::function<void(void)> func)
{
    this->Keymap[key] = func;
}

void Event2d::addMouse(sf::Mouse::Button button, std::function<void(void)> func)
{
    this->Mousemap[button] = func;
}

void Event2d::addJoystickAxis(sf::Joystick::Axis axis, std::function<void(void)> func)
{
    this->JoystickAxis[axis] = func;
}

void Event2d::addJoystickButton(unsigned int button, std::function<void(void)> func)
{
    this->JoystickButton[button] = func;
}

void Event2d::destroyEvent(sf::Event::EventType type)
{
    this->EventType.erase(type);
}

void Event2d::destroyKey(sf::Keyboard::Key key)
{
    this->Keymap.erase(key);
}

void Event2d::destroyMouse(sf::Mouse::Button button)
{
    this->Mousemap.erase(button);
}

void Event2d::destroyJoystickAxis(sf::Joystick::Axis axis)
{
    this->JoystickAxis.erase(axis);
}

void Event2d::destroyJoystickButton(unsigned int button)
{
    this->JoystickButton.erase(button);
}

void Event2d::manageEvent(sf::Event event)
{
    for (auto it = this->EventType.begin(); it != this->EventType.end(); it++) {
        if (event.type == sf::Event::KeyPressed && this->Keymap.find(event.key.code) != this->Keymap.end()) {
            std::cout << "key pressed" << std::endl;
            return this->Keymap[event.key.code]();
        }
        if (event.type == sf::Event::MouseButtonPressed && this->Mousemap.find(event.mouseButton.button) != this->Mousemap.end()) {
            std::cout << "mouse pressed" << std::endl;
            return this->Mousemap[event.mouseButton.button]();
        }
        if (event.type == sf::Event::JoystickButtonPressed && this->JoystickButton.find(event.joystickButton.button) != this->JoystickButton.end()) {
            std::cout << "joystick pressed" << std::endl;
            return this->JoystickButton[event.joystickButton.button]();
        }
        if (event.type == sf::Event::JoystickMoved && this->JoystickAxis.find(event.joystickMove.axis) != this->JoystickAxis.end()) {
            std::cout << "joystick moved" << std::endl;
            return this->JoystickAxis[event.joystickMove.axis]();
        }
        if (event.type == it->first) {
            return it->second();
        }
    }
}
