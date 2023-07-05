/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Event3d
*/

#include "Event3d.hpp"

Button::Button(std::uint32_t button, enum ButtonStatus status, std::uint32_t joystickId = 0)
{
    this->button = button;
    this->joystickId = joystickId;
    this->status = status;
    this->isPressed = false;
}

Button::~Button()
{
}

void Button::setPressed(bool pressed)
{
    this->isPressed = pressed;
}

void Button::setStatus(enum ButtonStatus status)
{
    this->status = status;
}

bool Button::getPressed(void)
{
    return this->isPressed;
}

enum ButtonStatus Button::getStatus(void)
{
    return this->status;
}

std::uint32_t Button::getButton(void)
{
    return this->button;
}

std::uint32_t Button::getJoystickId(void)
{
    return this->joystickId;
}

Event3d::Event3d()
{
    this->MouseStatus = true;
    this->KeyboardStatus = true;
    this->JoystickMaxCount = 0;
    this->JoystickCount = 0;
    this->JoystickDeadZone = 0.1;
    this->JoystickStatus = false;
}

Event3d::~Event3d(void)
{
    this->Keymap.clear();
    this->Mousemap.clear();
    this->JoystickAxis.clear();
    this->JoystickButton.clear();
}

void Event3d::addKey(std::uint32_t key, enum ButtonStatus status,std::function<void(void)> func)
{
    auto newKey = std::make_shared<Button>(key, status);
    this->Keymap[newKey] = func;
}

void Event3d::addMouse(std::uint32_t button, enum ButtonStatus status, std::function<void(void)> func)
{
    auto newMouse =  std::make_shared<Button>(button, status);
    this->Mousemap[newMouse] = func;
}

void Event3d::addJoystickAxis(std::array<std::uint32_t, 2>& axis, std::function<void(float)> func)
{
    this->JoystickAxis[axis] = func;
}

void Event3d::addJoystickButton(std::array<std::uint32_t, 2>& button, enum ButtonStatus status, std::function<void(void)> func)
{
    auto newButton =  std::make_shared<Button>(std::get<0>(button), status, std::get<1>(button));
    this->JoystickButton[newButton] = func;
}

void Event3d::manageEvent(GLFWwindow *window)
{
    int tmp = 0;
    for (this->JoystickCount = 0; this->JoystickCount < GLFW_JOYSTICK_LAST && this->JoystickCount < this->JoystickMaxCount; this->JoystickCount++) {
        if (!glfwJoystickPresent(this->JoystickCount))
            break;
    }
    if (this->KeyboardStatus) {
        for (auto it = this->Keymap.begin(); it != this->Keymap.end(); it++) {
            tmp = glfwGetKey(window, it->first->getButton());
            if (tmp == GLFW_PRESS && (!it->first->getPressed() || it->first->getStatus() == PRESSED)) {
                it->first->setPressed(true);
                it->second();
            }
            if (tmp == GLFW_RELEASE)
                it->first->setPressed(false);
        }
    }
    if (this->MouseStatus) {
        for (auto it = this->Mousemap.begin(); it != this->Mousemap.end(); it++) {
            tmp = glfwGetMouseButton(window, it->first->getButton());
            if (tmp == GLFW_PRESS && (!it->first->getPressed() || it->first->getStatus() == PRESSED)) {
                it->first->setPressed(true);
                it->second();
            }
            if (tmp == GLFW_RELEASE)
                it->first->setPressed(false);
        }
    }
    if (this->JoystickStatus) {
        for (int JoystickId = 0; JoystickId < this->getJoystickCount(); JoystickId++) {
            int count = 0;
            const float *axes = glfwGetJoystickAxes(JoystickId, &count);
            for (auto it = this->JoystickAxis.begin(); it != this->JoystickAxis.end(); it++) {
                if (it->first[0] < count && (axes[it->first[1]] > this->JoystickDeadZone || axes[it->first[1]] < -this->JoystickDeadZone))
                    it->second(axes[it->first[1]]);
            }
            count = 0;
            const unsigned char * button = glfwGetJoystickButtons(JoystickId, &count);
            for (auto it = this->JoystickButton.begin(); it != this->JoystickButton.end(); it++) {
                if (JoystickId == it->first->getJoystickId() && it->first->getButton() < count && button[it->first->getButton()] == GLFW_PRESS && (!it->first->getPressed() || it->first->getStatus() == PRESSED)) {
                    it->first->setPressed(true);
                    it->second();
                }
                if (JoystickId == it->first->getJoystickId() && button[it->first->getButton()] == GLFW_RELEASE)
                    it->first->setPressed(false);
            }
        }
    }
}

void Event3d::deleteKey(std::uint32_t key)
{
    for (auto it = this->Keymap.begin(); it != this->Keymap.end(); it++) {
        if (it->first->getButton() == key) {
            this->Keymap.erase(it);
            break;
        }
    }
}

void Event3d::deleteMouse(std::uint32_t button)
{
    for (auto it = this->Mousemap.begin(); it != this->Mousemap.end(); it++) {
        if (it->first->getButton() == button) {
            this->Mousemap.erase(it);
            break;
        }
    }
}

void Event3d::deleteJoystickAxis(std::array<std::uint32_t, 2>& axis)
{
    this->JoystickAxis.erase(axis);
}

void Event3d::deleteJoystickButton(std::array<std::uint32_t, 2>& button)
{
    for (auto it = this->JoystickButton.begin(); it != this->JoystickButton.end(); it++) {
        if (it->first->getButton() == std::get<0>(button) && it->first->getStatus() == std::get<1>(button)) {
            this->JoystickButton.erase(it);
            break;
        }
    }
}

void Event3d::disableJoystick(void)
{
    this->JoystickStatus = false;
}

void Event3d::disableKeyboard(void)
{
    this->KeyboardStatus = false;
}

void Event3d::disableMouse(void)
{
    this->MouseStatus = false;
}

bool Event3d::enableJoystick(void)
{
    if (!glfwJoystickPresent(GLFW_JOYSTICK_1))
        return false;
    this->JoystickStatus = true;
    return true;
}

void Event3d::enableKeyboard(void)
{
    this->KeyboardStatus = true;
}

void Event3d::enableMouse(void)
{
    this->MouseStatus = true;
}

bool Event3d::isJoystickEnabled(void)
{
    return this->JoystickStatus;
}

bool Event3d::isKeyboardEnabled(void)
{
    return this->KeyboardStatus;
}

bool Event3d::isMouseEnabled(void)
{
    return this->MouseStatus;
}

bool Event3d::isKeyManaged(std::uint32_t key)
{
    for (auto it = this->Keymap.begin(); it != this->Keymap.end(); it++) {
        if (it->first->getButton() == key)
            return true;
    }
    return false;
}

bool Event3d::isMouseManaged(std::uint32_t button)
{
    for (auto it = this->Mousemap.begin(); it != this->Mousemap.end(); it++) {
        if (it->first->getButton() == button)
            return true;
    }
    return false;
}

bool Event3d::isJoystickAxisManaged(std::array<std::uint32_t, 2>& axis)
{
    for (auto it = this->JoystickAxis.begin(); it != this->JoystickAxis.end(); it++) {
        if (it->first[0] == std::get<0>(axis) && it->first[1] == std::get<1>(axis))
            return true;
    }
    return false;
}

bool Event3d::isJoystickButtonManaged(std::array<std::uint32_t, 2>& button)
{
    for (auto it = this->JoystickButton.begin(); it != this->JoystickButton.end(); it++) {
        if (it->first->getButton() == std::get<0>(button) && it->first->getStatus() == std::get<1>(button))
            return true;
    }
    return false;
}

void Event3d::setJoystickAxisDeadZone(std::float_t deadZone)
{
    this->JoystickDeadZone = deadZone;
}

float Event3d::getJoystickAxisDeadZone(void)
{
    return this->JoystickDeadZone;
}

void Event3d::setJoystickMaxCount(std::uint32_t count)
{
    this->JoystickMaxCount = count;
}

std::uint32_t Event3d::getJoystickMaxCount(void)
{
    return this->JoystickMaxCount;
}

std::uint32_t Event3d::getJoystickCount(void)
{
    return this->JoystickCount;
}

void Event3d::displayPressedJoystciButton(void)
{
    unsigned char * buttons = NULL;
    int count = 0;
    for (int joystickId = 0; joystickId < this->JoystickMaxCount; joystickId++) {
        buttons = (unsigned char *)glfwGetJoystickButtons(joystickId, &count);
        if (buttons == NULL)
            continue;
        for (int button = 0; button < count; button++) {
            if (buttons[button] == GLFW_PRESS)
                std::cout << "Joystick " << joystickId << " button " << button << " pressed" << std::endl;
        }
    }
}
