/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Shader
*/

#include "opengl_include.hpp"

#ifndef SHADER_HPP_
#define SHADER_HPP_

class Shader {
    public:
        unsigned int ID;

        Shader(const std::string vertexPath, const std::string fragmentPath);
        ~Shader();

        void use();
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;

    protected:
    private:
};

#endif /* !SHADER_HPP_ */
