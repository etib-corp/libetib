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
        std::double_t getElapsedTime();
        std::double_t getElapsedTimeAsSeconds();
        std::double_t getDeltaTime();

    protected:
    private:
    std::double_t lastTime;
    std::double_t currentTime;
    std::double_t deltaTime;
    std::double_t time;
};

#endif /* !CLOCK3D_HPP_ */
