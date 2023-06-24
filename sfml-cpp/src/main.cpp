/*
** EPITECH PROJECT, 2023
** cpp
** File description:
** main
*/

/* DO NOT MOVE ALL INCLUDE INSIDE OF SFML_INCLUDE SINCE THIS MAIN ISN'T FOR RELEASE */
/* 2D INCLUDE */
#include "Event2d.hpp"
#include "Window2d.hpp"
#include "Entity2d.hpp"
#include "JSONParser.hpp"

/* 3D INCLUDE */
#include "Window3d.hpp"
#include "Text3d.hpp"

void addAllEvent(Window2d *&window)
{
    window->addEvent(sf::Event::Closed, [&window]() {
        window->close();
    });
    window->addKey(sf::Keyboard::Escape, [&window]() {
        window->close();
    });
}

void test_2d(void)
{
    JSONParser *parser = new JSONParser("./src/main.cpp");
    Window2d *window = new Window2d();
    addAllEvent(window);
    while (window->isOpen()) {
        window->manageEvent();
        window->clear(sf::Color::Black);
        window->display();
    }
}

void test_3d(void)
{
    Window3d *window = new Window3d(800, 600, "Hello World");
    int ind = 0;
    glm::vec4 colors[8] = {YELLOW, GREEN, BLUE, RED, CYAN, MAGENTA, WHITE, BLACK};
    glm::vec4 actualColor = colors[0];
    window->addKey(GLFW_KEY_ESCAPE, JUST_PRESSED, [&window]() {
        window->close();
    });
    window->addKey(GLFW_KEY_SPACE, JUST_PRESSED, [&window, &ind, &colors, &actualColor]() {
        ind++;
        if (ind > 7)
            ind = 0;
        actualColor = colors[ind];
    });
    window->addKey(GLFW_KEY_C, JUST_PRESSED, [&window, &ind, &colors, &actualColor]() {
        std::cout << "C" << std::endl;
    });
    window->addKey(GLFW_KEY_E, JUST_PRESSED, [&window, &ind, &colors, &actualColor]() {
        std::cout << window->isKeyManaged(GLFW_KEY_C) << std::endl;
        window->deleteKey(GLFW_KEY_C);
        std::cout << window->isKeyManaged(GLFW_KEY_C) << std::endl;
    });
    std::array<unsigned int, 2> axis0 = {0, GLFW_JOYSTICK_1};
    std::array<unsigned int, 2> axis1 = {0, GLFW_JOYSTICK_2};
    std::array<unsigned int, 2> axis2 = {1, GLFW_JOYSTICK_1};
    std::array<unsigned int, 2> axis3 = {1, GLFW_JOYSTICK_2};
    window->addJoystickButton(axis0, JUST_PRESSED, [&actualColor]() {
        actualColor = ORANGE;
    });
    window->addJoystickButton(axis1, PRESSED, [&actualColor]() {
        actualColor = BLUE;
    });
    window->addJoystickButton(axis2, JUST_PRESSED, [&actualColor]() {
        actualColor = RED;
    });
    window->addJoystickButton(axis3, JUST_PRESSED, [&actualColor]() {
        actualColor = GREEN;
    });
    //window->enableJoystick();
    //window->setJoystickMaxCount(2);
    //window->setFramerateLimit(60);
    Text * text = new Text("./assets/font/arial.ttf", 48, 800, 600);
    Shader * shader = new Shader("./assets/shader/TextVertexShader.vertexshader", "./assets/shader/TextFragmentShader.fragmentshader");
    window->setShader(shader);
    shader->use();
    while (window->isOpen()) {
        window->clear(actualColor);
        window->updateFramerate();
        text->drawText(shader, "Hello World", 25.0, 25.0, 1.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        window->swapBuffers();
        window->pollEvents();
        window->manageEvent();
    }
    delete window;
}

int main(void)
{
    test_3d();
    return 0;
}
