/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Window
*/

#include "Window3d.hpp"

Window3d::Window3d(unsigned int width, unsigned int height, std::string title, GLFWmonitor *monitor, GLFWwindow *share)
{
    if (!glfwInit())
        throw std::runtime_error("Failed to init glfw");

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(width, height, title.c_str(), monitor, share);
    if (!this->window)
        throw std::runtime_error("Failed to create window");

    glfwMakeContextCurrent(this->window);
    glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    this->event = new Event3d();
}

Window3d::~Window3d()
{
}

void Window3d::clear(glm::vec4 color)
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window3d::close()
{
    glfwSetWindowShouldClose(this->window, 1);
}

Event3d *Window3d::getEvent()
{
    return this->event;
}

GLFWwindow *Window3d::getWindow()
{
    return this->window;
}

bool Window3d::isOpen()
{
    return !glfwWindowShouldClose(this->window);
}

void Window3d::pollEvents()
{
    glfwPollEvents();
}

void Window3d::swapBuffers()
{
    glfwSwapBuffers(this->window);
}

/* EVENT */

void Window3d::addKey(unsigned int key, enum ButtonStatus status, std::function<void(void)> func)
{
    this->event->addKey(key, status, func);
}

void Window3d::addMouse(unsigned int button, enum ButtonStatus status, std::function<void(void)> func)
{
    this->event->addMouse(button, status, func);
}

void Window3d::addJoystickAxis(std::array<unsigned int, 2>& axis, std::function<void(float)> func)
{
    this->event->addJoystickAxis(axis, func);
}

void Window3d::addJoystickButton(std::array<unsigned int, 2>& button, enum ButtonStatus status, std::function<void(void)> func)
{
    this->event->addJoystickButton(button, status, func);
}

void Window3d::manageEvent()
{
    this->event->manageEvent(this->window);
}

void Window3d::deleteKey(unsigned int key)
{
    this->event->deleteKey(key);
}

void Window3d::deleteMouse(unsigned int button)
{
    this->event->deleteMouse(button);
}

void Window3d::deleteJoystickAxis(std::array<unsigned int, 2>& axis)
{
    this->event->deleteJoystickAxis(axis);
}

void Window3d::deleteJoystickButton(std::array<unsigned int, 2> &button)
{
    this->event->deleteJoystickButton(button);
}

void Window3d::disableJoystick(void)
{
    this->event->disableJoystick();
}

void Window3d::disableKeyboard(void)
{
    this->event->disableKeyboard();
}

void Window3d::disableMouse(void)
{
    this->event->disableMouse();
}

void Window3d::enableJoystick(void)
{
    this->event->enableJoystick();
}

void Window3d::enableKeyboard(void)
{
    this->event->enableKeyboard();
}

void Window3d::enableMouse(void)
{
    this->event->enableMouse();
}

bool Window3d::isKeyManaged(unsigned int key)
{
    return this->event->isKeyManaged(key);
}

bool Window3d::isMouseManaged(unsigned int button)
{
    return this->event->isMouseManaged(button);
}

bool Window3d::isJoystickAxisManaged(std::array<unsigned int, 2>& axis)
{
    return this->event->isJoystickAxisManaged(axis);
}

bool Window3d::isJoystickButtonManaged(std::array<unsigned int, 2>& button)
{
    return this->event->isJoystickButtonManaged(button);
}

bool Window3d::isJoystickEnabled(void)
{
    return this->event->isJoystickEnabled();
}

bool Window3d::isKeyboardEnabled(void)
{
    return this->event->isKeyboardEnabled();
}

bool Window3d::isMouseEnabled(void)
{
    return this->event->isMouseEnabled();
}

void Window3d::setJoystickAxisDeadZone(float deadZone)
{
    this->event->setJoystickAxisDeadZone(deadZone);
}

float Window3d::getJoystickAxisDeadZone(void)
{
    return this->event->getJoystickAxisDeadZone();
}

void Window3d::setJoystickMaxCount(unsigned int count)
{
    this->event->setJoystickMaxCount(count);
}

unsigned int Window3d::getJoystickMaxCount(void)
{
    return this->event->getJoystickMaxCount();
}

unsigned int Window3d::getJoystickCount(void)
{
    return this->event->getJoystickCount();
}

/* CURSOR VISIBILITY */

void Window3d::setMouseCursorVisible(bool visible)
{
    if (visible)
        glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    else
        glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

bool Window3d::getMouseCursorVisible(void)
{
    return this->isMouseCursorVisible;
}