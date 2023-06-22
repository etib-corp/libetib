/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Event3d
*/

#include "opengl_include.hpp"

#ifndef EVENT3D_HPP_
#define EVENT3D_HPP_

enum ButtonStatus {
    JUST_PRESSED,
    PRESSED
};

class Button {
    public:
        Button(unsigned int button, enum ButtonStatus status, unsigned int joystickId);
        ~Button();
        void setPressed(bool pressed);
        void setStatus(enum ButtonStatus status);
        bool getPressed(void);
        enum ButtonStatus getStatus(void);
        unsigned int getButton(void);
        unsigned int getJoystickId(void);
    protected:
    private:
        unsigned int button;
        unsigned int joystickId;
        enum ButtonStatus status;
        bool isPressed;
};

class Event3d {
    public:
        Event3d();
        ~Event3d(void);
        void addKey(unsigned int key, enum ButtonStatus status, std::function<void(void)> func);
        void addMouse(unsigned int button, enum ButtonStatus status, std::function<void(void)> func);
        void addJoystickAxis(std::array<unsigned int, 2>& axis, std::function<void(float)> func);
        void addJoystickButton(std::array<unsigned int, 2>& button, enum ButtonStatus status, std::function<void(void)> func);
        void manageEvent(GLFWwindow *window);
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
        void displayPressedJoystciButton(void);
    protected:
    private:
        std::map<Button *, std::function<void(void)>> Keymap;
        std::map<Button *, std::function<void(void)>> Mousemap;
        std::map<std::array<unsigned int, 2>, std::function<void(float strengh)>> JoystickAxis;
        std::map<Button *, std::function<void(void)>> JoystickButton;
        bool MouseStatus;
        bool KeyboardStatus;
        unsigned int JoystickMaxCount;
        unsigned int JoystickCount;
        float JoystickDeadZone;
        bool JoystickStatus;
};

#endif /* !EVENT3D_HPP_ */
