/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "sfml_include.hpp"

class Entity {
    protected:
        sf::Vector2f velocity;
        sf::Vector2f position;
    public:
        Entity();
        ~Entity();
};

#endif /* !ENTITY_HPP_ */
