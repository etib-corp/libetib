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
    glm::vec4 colors[8] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, BLACK};
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
    while (window->isOpen()) {
        window->clear(actualColor);
        window->swapBuffers();
        window->pollEvents();
        window->manageEvent();
    }
}

int main(void)
{
    test_3d();
    return 0;
}
