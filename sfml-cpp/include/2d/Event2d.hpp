/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Event2d
*/

#ifndef EVENT2D_HPP_
#define EVENT2D_HPP_

#ifndef  EVENTCONDITION2D_HPP_
#include "Event2dCondition.hpp"
#endif /* !EVENTCONDITION2D_HPP_ */

#include "sfml_include.hpp"

class Event2d {
    private:
    std::map<sf::Event::EventType, std::function<void(void)>> EventType;
    std::map<sf::Keyboard::Key, std::function<void(void)>> Keymap;
    std::map<sf::Mouse::Button, std::function<void(void)>> Mousemap;
    std::map<sf::Joystick::Axis, std::function<void(void)>> JoystickAxis;
    std::map<unsigned int, std::function<void(void)>> JoystickButton;

    public:
    Event2d();
    ~Event2d();
    void addEvent(sf::Event::EventType type, std::function<void(void)> func);
    void addKey(sf::Keyboard::Key key, std::function<void(void)> func);
    void addMouse(sf::Mouse::Button button, std::function<void(void)> func);
    void addJoystickAxis(sf::Joystick::Axis axis, std::function<void(void)> func);
    void addJoystickButton(unsigned int, std::function<void(void)> func);
    void destroyEvent(sf::Event::EventType type);
    void destroyKey(sf::Keyboard::Key key);
    void destroyMouse(sf::Mouse::Button button);
    void destroyJoystickAxis(sf::Joystick::Axis axis);
    void destroyJoystickButton(unsigned int button);
    void manageEvent(sf::Event);
};

#endif /* !EVENT2D_HPP_ */
