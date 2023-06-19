/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "sfml_include.hpp"

class Entity2d {
    protected:
        sf::Vector2f velocity;
        sf::Vector2f position;
        sf::RectangleShape shape;

    public:
        Entity2d();
        ~Entity2d();
        void move(sf::Vector2f velocity);
};

#endif /* !ENTITY_HPP_ */
