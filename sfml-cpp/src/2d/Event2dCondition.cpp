/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Event2dCondition
*/
#include "Event2dCondition.hpp"

bool isWindowClosed(sf::Event event)
{
    if (event.type == sf::Event::Closed)
        return true;
    return false;
}
std::function<bool(sf::Event)> isKeyPressed = [key](sf::Event event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == key)
        return true;
    return false;
};