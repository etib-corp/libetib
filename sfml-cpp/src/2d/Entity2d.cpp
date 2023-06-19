/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** entity
*/

#include "Entity2d.hpp"

Entity2d::Entity2d()
{
}

Entity2d::~Entity2d()
{
}

void Entity2d::move(sf::Vector2f velocity)
{
    this->position += velocity;
}
