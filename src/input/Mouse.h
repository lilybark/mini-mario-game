//
// Created by meili on 6/2/2024.
//

#ifndef MINI_MARIO_MOUSE_H
#define MINI_MARIO_MOUSE_H

#include "GLFW/glfw3.h"

namespace MiniMario {

    // forward decls
    namespace Math {
        class Vec2;
    }

    class Mouse {
    public:

        enum Button {
            // enum values matched to GLFW macro enum values

            BUTTON_1        = 0,
            BUTTON_2        = 1,
            // buttons after this one are often used for mouses with side buttons
            BUTTON_3        = 2,
            BUTTON_4        = 3,
            BUTTON_5        = 4,
            BUTTON_6        = 5,
            BUTTON_7        = 6,
            BUTTON_8        = 7,

            BUTTON_RIGHT    = BUTTON_2,
            BUTTON_LEFT     = BUTTON_1,
        };

        enum Mods {
            SHIFT = 0x0001,
            CONTROL = 0x0002,
            ALT = 0x0004,
            SUPER = 0x0008,
            CAPS_LOCK = 0x0010,
            NUM_LOCK = 0x0020,
        };

        static bool isPressed(Button k);
        static bool modsCheck(Mods m);
        static Math::Vec2 pos();
        static Math::Vec2 dPos();
        /**
         * Gets the current scroll of the mouse.
         * @return The mouse's current scroll (in the Y direction)
         */
        static double scroll();
        /**
         * Gets the two-dimensional scroll of the mouse. Less commonly used, as most mouses typically have a single direction for scrolling.
         * @return The XY scroll
         */
        static Math::Vec2 scrollXY();

        static void glfwPosCallback(GLFWwindow *w, double xpos, double ypos);
        static void glfwScrollCallback(GLFWwindow *w, double xoffset, double yoffset);
        static void glfwButtonCallback(GLFWwindow *w, int button, int action, int mods);


    private:
        Mouse() = default;
        static Mouse &get();
        // internal state for which keys and modifiers GLFW has registered to be pressed or repeated.
        bool pressedButtons[8];
        Mods modifiers{};
        double posX, posY, dPosX, dPosY;
        double scrollX, scrollY, dScrollX, dScrollY;

        static Mouse *_inst;
    };

} // MiniMario

#endif //MINI_MARIO_MOUSE_H
