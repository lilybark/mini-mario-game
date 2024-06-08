//
// Created by meili on 6/2/2024.
//

#include "Mouse.h"
#include "math/Vec2.h"

namespace MiniMario {
    bool Mouse::isPressed(Mouse::Button b) {
        return Mouse::get().pressedButtons[static_cast<size_t>(b)];
    }

    Mouse &Mouse::get() {
        if (!_inst) _inst = new Mouse();
        return *_inst;
    }

    Mouse *Mouse::_inst = nullptr;

    bool Mouse::modsCheck(Mouse::Mods m) {
        return (m == Mouse::get().modifiers);
    }

    Math::Vec2 Mouse::pos() {
        return {static_cast<float>(Mouse::get().posX), static_cast<float>(Mouse::get().posY)};
    }

    Math::Vec2 Mouse::dPos() {
        return {static_cast<float>(Mouse::get().dPosX), static_cast<float>(Mouse::get().dPosY)};
    }

    double Mouse::scroll() {
        return static_cast<float>(Mouse::get().scrollY);
    }

    Math::Vec2 Mouse::scrollXY() {
        return {static_cast<float>(Mouse::get().scrollX), static_cast<float>(Mouse::get().scrollY)};
    }

    void Mouse::glfwPosCallback(GLFWwindow *, double xpos, double ypos) {
        Mouse::get().dPosX = static_cast<float>(xpos) - Mouse::get().posX;
        Mouse::get().dPosY = static_cast<float>(ypos) - Mouse::get().posY;

        Mouse::get().posX = static_cast<float>(xpos);
        Mouse::get().posY = static_cast<float>(ypos);
    }

    void Mouse::glfwScrollCallback(GLFWwindow *, double xoffset, double yoffset) {
        Mouse::get().scrollX = xoffset;
        Mouse::get().scrollY = yoffset;
    }

    void Mouse::glfwButtonCallback(GLFWwindow *, int button, int action, int mods) {
        Mouse::get().modifiers = static_cast<Mods>(mods);
        if (action == GLFW_PRESS) {
            Mouse::get().pressedButtons[button] = true;
        } else {
            Mouse::get().pressedButtons[button] = false;
        }

    }
} // MiniMario