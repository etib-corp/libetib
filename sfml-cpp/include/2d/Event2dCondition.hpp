/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Event2dCondition
*/

#ifndef EVENT2DCONDITION_HPP_
#define EVENT2DCONDITION_HPP_

#include "sfml_include.hpp"

bool isWindowClosed(sf::Event event, va_list *ap);
bool isKeyPressed(sf::Event event, va_list *ap);


#endif /* !EVENT2DCONDITION_HPP_ */
