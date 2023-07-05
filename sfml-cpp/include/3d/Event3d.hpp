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
        Button(std::uint8_t button, enum ButtonStatus status, std::uint8_t joystickId);
        ~Button();
        void setPressed(bool pressed);
        void setStatus(enum ButtonStatus status);
        bool getPressed(void);
        enum ButtonStatus getStatus(void);
        std::uint8_t getButton(void);
        std::uint8_t getJoystickId(void);
    protected:
    private:
        std::uint8_t button;
        std::uint8_t joystickId;
        enum ButtonStatus status;
        bool isPressed;
};

class Event3d {
    public:
        Event3d();
        ~Event3d(void);
        void addKey(std::uint8_t key, enum ButtonStatus status, std::function<void(void)> func);
        void addMouse(std::uint8_t button, enum ButtonStatus status, std::function<void(void)> func);
        void addJoystickAxis(std::array<std::uint8_t, 2>& axis, std::function<void(float)> func);
        void addJoystickButton(std::array<std::uint8_t, 2>& button, enum ButtonStatus status, std::function<void(void)> func);
        void manageEvent(GLFWwindow *window);
        void deleteKey(std::uint8_t key);
        void deleteMouse(std::uint8_t button);
        void deleteJoystickAxis(std::array<std::uint8_t, 2>& axis);
        void deleteJoystickButton(std::array<std::uint8_t, 2> &button);
        void disableJoystick(void);
        void disableKeyboard(void);
        void disableMouse(void);
        bool enableJoystick(void);
        void enableKeyboard(void);
        void enableMouse(void);
        bool isKeyManaged(std::uint8_t key);
        bool isMouseManaged(std::uint8_t button);
        bool isJoystickAxisManaged(std::array<std::uint8_t, 2>& axis);
        bool isJoystickButtonManaged(std::array<std::uint8_t, 2>& button);
        bool isJoystickEnabled(void);
        bool isKeyboardEnabled(void);
        bool isMouseEnabled(void);
        void setJoystickAxisDeadZone(std::float_t deadZone);
        std::float_t getJoystickAxisDeadZone(void);
        void setJoystickMaxCount(std::uint8_t count);
        std::uint8_t getJoystickMaxCount(void);
        std::uint8_t getJoystickCount(void);
        void displayPressedJoystciButton(void);
    protected:
    private:
        std::map<std::shared_ptr<Button>, std::function<void(void)>> Keymap;
        std::map<std::shared_ptr<Button>, std::function<void(void)>> Mousemap;
        std::map<std::array<std::uint8_t, 2>, std::function<void(std::float_t strengh)>> JoystickAxis;
        std::map<std::shared_ptr<Button>, std::function<void(void)>> JoystickButton;
        bool MouseStatus;
        bool KeyboardStatus;
        std::uint8_t JoystickMaxCount;
        std::uint8_t JoystickCount;
        float JoystickDeadZone;
        bool JoystickStatus;
};

#endif /* !EVENT3D_HPP_ */
