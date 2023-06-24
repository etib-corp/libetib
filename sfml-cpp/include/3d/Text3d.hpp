/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Text
*/

#include "opengl_include.hpp"
#include "Shader.hpp"

#ifndef TEXT_HPP_
#define TEXT_HPP_

struct Character {
    unsigned int textureID;
    glm::ivec2 size;
    glm::ivec2 bearing;
    unsigned int advance;
};

class Text {
    public:
        Text(std::string fontpath, unsigned int size, float screenWidth, float screenHeight);
        ~Text();
        void drawText(Shader *s, std::string text, float x, float y, float scale, glm::vec3 color);

    protected:
    private:
        std::string fontpath;
        FT_Library ft;
        FT_Face face;
        unsigned int size;
        std::map<char, Character> characters;
        glm::mat4 projection;
        unsigned int VAO;
        unsigned int VBO;
};

#endif /* !TEXT_HPP_ */
