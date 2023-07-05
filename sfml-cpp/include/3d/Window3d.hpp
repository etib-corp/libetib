/*
** EPITECH PROJECT, 2023
** sfml-cpp
** File description:
** Window
*/

#include "opengl_include.hpp"
#include "Event3d.hpp"
#include "Clock3d.hpp"
#include "Shader.hpp"

#ifndef WINDOW3D_HPP_
#define WINDOW3D_HPP_
#include "Colors.hpp"

class Window3d {
    public:
        Window3d(std::uint32_t width, std::uint32_t height, std::string title, GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr);
        ~Window3d();
        void clear(glm::vec4 color);
        void close();
        std::shared_ptr<Event3d> getEvent();
        GLFWwindow *getWindow();
        bool isOpen();
        void pollEvents();
        void swapBuffers();

        void addKey(std::uint8_t key, enum ButtonStatus status, std::function<void(void)> func);
        void addMouse(std::uint8_t button, enum ButtonStatus status, std::function<void(void)> func);
        void addJoystickAxis(std::array<std::uint8_t, 2>& axis, std::function<void(std::float_t)> func);
        void addJoystickButton(std::array<std::uint8_t, 2>& button, enum ButtonStatus status, std::function<void(void)> func);
        void manageEvent();
        void deleteKey(std::uint8_t key);
        void deleteMouse(std::uint8_t button);
        void deleteJoystickAxis(std::array<std::uint8_t, 2>& axis);
        void deleteJoystickButton(std::array<std::uint8_t, 2> &button);
        void disableJoystick(void);
        void disableKeyboard(void);
        void disableMouse(void);
        void enableJoystick(void);
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

        void setMouseCursorVisible(bool visible);
        bool getMouseCursorVisible(void);

        void setFramerateLimit(std::uint32_t limit);
        std::uint32_t getFramerateLimit(void);
        std::uint32_t getFramerate(void);
        void updateFramerate(void);
        std::double_t getElapsedTime(void);
        std::double_t getDeltaTime(void);
        void restartClock(void);

        void setShader(Shader *shader);
        Shader *getShader(void);
    protected:
    private:
        GLFWwindow *window;
        GLFWmonitor *monitor;
        const GLFWvidmode *mode;
        std::shared_ptr<Event3d> event;
        std::shared_ptr<Clock3d> clock;
        Shader *shader;
        bool isMouseCursorVisible;
        std::uint32_t framerateLimit;
        std::uint32_t framerate;
};

#endif /* !WINDOW3D_HPP_ */
