//
// Created by meili on 6/1/2024.
//

#include <iostream>
#include <bitset>
#include "Keyboard.h"

namespace MiniMario {
    void Keyboard::glfwCallback(GLFWwindow *, int key, int scancode, int action, int mods) {
        switch (action) {
            case GLFW_PRESS:
                Keyboard::get().pressedKeys[key] = true;
                Keyboard::get().modifiers = static_cast<Mods>(mods);
                break;
            case GLFW_RELEASE:
                Keyboard::get().pressedKeys[key] = false;
                Keyboard::get().repeatedKeys[key] = false;
                Keyboard::get().modifiers = static_cast<Mods>(0);
                break;
            case GLFW_REPEAT:
                Keyboard::get().repeatedKeys[key] = true;
                Keyboard::get().modifiers = static_cast<Mods>(mods);
                break;
            default:
                std::cerr << "Invalid key action: " << action << ", " << std::endl;
                exit(-1);
        }

    }

    bool Keyboard::isPressed(Key k) {
        return Keyboard::get().pressedKeys[static_cast<size_t>(k)];
    }
    bool Keyboard::checkMods(Mods k) {
        if (static_cast<size_t>(k) > 0x003f) {
            std::cerr << "Invalid modifier key code: " << std::bitset<8>(k) << std::endl;
            exit(-1);
        }

        return (k == Keyboard::get().modifiers);
    }

    bool Keyboard::isRepeated(Key k) {
        return Keyboard::get().pressedKeys[static_cast<size_t>(k)];
    }

    Keyboard &Keyboard::get() {
        if (!_inst) {
            _inst = new Keyboard();
        }
        return *_inst;
    }

    Keyboard *Keyboard::_inst = nullptr;
} // MiniMario