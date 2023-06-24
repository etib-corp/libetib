/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Clock3d
*/

#include "Clock3d.hpp"

Clock3d::Clock3d()
{
    this->lastTime = glfwGetTime();
    this->currentTime = 0.0;
    this->deltaTime = 0.0;
    this->time = 0.0;
}

Clock3d::~Clock3d()
{
}

void Clock3d::restart()
{
    this->lastTime = glfwGetTime();
}

void Clock3d::update()
{
    this->currentTime = glfwGetTime();
    this->deltaTime = this->currentTime - this->lastTime;
    this->lastTime = this->currentTime;
    this->time += this->deltaTime;
}

double Clock3d::getElapsedTime()
{
    return this->deltaTime;
}

double Clock3d::getElapsedTimeAsSeconds()
{
    return this->time / 1000.0;
}

double Clock3d::getDeltaTime()
{
    return this->deltaTime;
}