/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Window
*/

#include "Window3d.hpp"
#include "Clock3d.hpp"
#include "Shader.hpp"

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
    glfwSetFramebufferSizeCallback(this->window, [](GLFWwindow *window, int width, int height) {
        glViewport(0, 0, width, height);
        std::cout << "Window resized to " << width << "x" << height << std::endl;
    });
    glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    this->monitor = glfwGetPrimaryMonitor();
    this->mode = glfwGetVideoMode(this->monitor);
    this->isMouseCursorVisible = true;
    this->event = new Event3d();
    this->clock = new Clock3d();
    this->framerate = 0;
    this->framerateLimit = this->mode->refreshRate;
}

Window3d::~Window3d()
{
    delete this->event;
    delete this->clock;
    glfwDestroyWindow(this->window);
    glfwTerminate();
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
    try {
        if (!this->event->enableJoystick()) {
            throw std::runtime_error("Failed to enable joystick");
        }
    } catch(...) {
        std::cout << "Please connect a joystick before enable it" << std::endl;
        delete this;
        exit(84);
    }
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

void Window3d::displayPressedJoystciButton(void)
{
    this->event->displayPressedJoystciButton();
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

/* FRAMERATE */

void Window3d::setFramerateLimit(unsigned int limit)
{
    if (limit == 0)
        glfwSwapInterval(0);
    else
        glfwSwapInterval(this->framerateLimit / limit);
}

unsigned int Window3d::getFramerateLimit(void)
{
    return this->framerateLimit;
}

unsigned int Window3d::getFramerate(void)
{
    return this->framerate;
}

void Window3d::updateFramerate(void)
{
    this->clock->update();
    this->framerate = 1 / this->clock->getElapsedTime();
    if (this->clock->getElapsedTime() >= 1)
        this->clock->restart();
}

double Window3d::getElapsedTime(void)
{
    return this->clock->getElapsedTime();
}

double Window3d::getDeltaTime(void)
{
    return this->clock->getDeltaTime();
}

void Window3d::restartClock(void)
{
    this->clock->restart();
}

void Window3d::setShader(Shader *shader)
{
    this->shader = shader;
}

Shader *Window3d::getShader(void)
{
    return this->shader;
}