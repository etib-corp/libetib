/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Clock3d
*/

#include "opengl_include.hpp"

#ifndef CLOCK3D_HPP_
#define CLOCK3D_HPP_

class Clock3d {
    public:
        Clock3d();
        ~Clock3d();
        void restart();
        void update();
        double getElapsedTime();
        double getElapsedTimeAsSeconds();
        double getDeltaTime();

    protected:
    private:
    double lastTime;
    double currentTime;
    double deltaTime;
    double time;
};

#endif /* !CLOCK3D_HPP_ */
