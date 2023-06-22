/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Window
*/

#include "opengl_include.hpp"
#include "Event3d.hpp"

#ifndef WINDOW3D_HPP_
#define WINDOW3D_HPP_
#include "Colors.hpp"

class Window3d {
    public:
        Window3d(unsigned int width, unsigned int height, std::string title, GLFWmonitor *monitor = NULL, GLFWwindow *share = NULL);
        ~Window3d();
        void clear(glm::vec4 color);
        void close();
        Event3d *getEvent();
        GLFWwindow *getWindow();
        bool isOpen();
        void pollEvents();
        void swapBuffers();

        void addKey(unsigned int key, enum ButtonStatus status, std::function<void(void)> func);
        void addMouse(unsigned int button, enum ButtonStatus status, std::function<void(void)> func);
        void addJoystickAxis(std::array<unsigned int, 2>& axis, std::function<void(float)> func);
        void addJoystickButton(std::array<unsigned int, 2>& button, enum ButtonStatus status, std::function<void(void)> func);
        void manageEvent();
        void deleteKey(unsigned int key);
        void deleteMouse(unsigned int button);
        void deleteJoystickAxis(std::array<unsigned int, 2>& axis);
        void deleteJoystickButton(std::array<unsigned int, 2> &button);
        void disableJoystick(void);
        void disableKeyboard(void);
        void disableMouse(void);
        void enableJoystick(void);
        void enableKeyboard(void);
        void enableMouse(void);
        bool isKeyManaged(unsigned int key);
        bool isMouseManaged(unsigned int button);
        bool isJoystickAxisManaged(std::array<unsigned int, 2>& axis);
        bool isJoystickButtonManaged(std::array<unsigned int, 2>& button);
        bool isJoystickEnabled(void);
        bool isKeyboardEnabled(void);
        bool isMouseEnabled(void);
        void setJoystickAxisDeadZone(float deadZone);
        float getJoystickAxisDeadZone(void);
        void setJoystickMaxCount(unsigned int count);
        unsigned int getJoystickMaxCount(void);
        unsigned int getJoystickCount(void);

        void setMouseCursorVisible(bool visible);
        bool getMouseCursorVisible(void);
    protected:
    private:
        GLFWwindow *window;
        Event3d *event;
        bool isMouseCursorVisible;
};

#endif /* !WINDOW3D_HPP_ */
