/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Text
*/

#include "Text3d.hpp"

Text::Text(std::string fontpath, unsigned int size, float screenWidth, float screenHeight)
{
    this->fontpath = fontpath;
    if (FT_Init_FreeType(&this->ft)) {
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        exit(84);
    }

    if (FT_New_Face(this->ft, fontpath.c_str(), 0, &this->face)) {
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
        exit(84);
    }
    FT_Set_Pixel_Sizes(this->face, 0, size);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    for (unsigned char c = 0; c < 128; c++) {
        if (FT_Load_Char(this->face, c, FT_LOAD_RENDER)) {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph for the char " << c << std::endl;
            continue;
        }
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        Character character = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            face->glyph->advance.x
        };
        characters.insert(std::pair<char, Character>(c, character));
    }
    FT_Done_Face(this->face);
    FT_Done_FreeType(this->ft);

    this->projection = glm::ortho(0.0f, screenWidth, 0.0f, screenHeight);

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Text::~Text()
{
}

void Text::drawText(Shader *s, std::string text, float x, float y, float scale, glm::vec3 color)
{
    s->use();
    glUniform3f(glGetUniformLocation(s->ID, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(this->VAO);

    std::string::const_iterator c;

    for (c = text.begin(); c != text.end(); c++) {
        Character ch = characters[*c];

        float xpos = x + ch.bearing.x * scale;
        float ypos = y - (ch.size.y - ch.bearing.y) * scale;

        float w = ch.size.x * scale;
        float h = ch.size.y * scale;

        float vertices[6][4] = {
            {xpos,      ypos + h,   0.0f,   0.0f},
            {xpos,      ypos,       0.0f,   1.0f},
            {xpos + w,  ypos,       1.0f,   1.0f},
            {xpos,      ypos + h,   0.0f,   0.0f},
            {xpos + w,  ypos,       1.0f,   1.0f},
            {xpos + w,  ypos + h,   1.0f,   0.0f}
        };

        glBindTexture(GL_TEXTURE_2D, ch.textureID);
        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        x += (ch.advance >> 6) * scale;
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
