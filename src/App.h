/* date = April 07, 2024 4:02 PM */

#ifndef MINI_MARIO_GAME_APP_H
#define MINI_MARIO_GAME_APP_H

#include <GLFW/glfw3.h>

namespace MiniMario {
    /**
     * # App
     *
     * This class handles the initialization of the program, the main window, and any button/mouse inputs from the user.
     * It's major backing is in GLFW.
     *
     * // TODO: make this a singleton???
     */
    class App {
    public:
        /**
         * Starts the MiniMario App, initializing primary window.
         */
        App();
        /**
         * Closes MiniMario, freeing any files or handles.
         */
        ~App();
        /**
         * Spins up the App, causing it to enter the game loop.
         */
        void run();
        double deltaTime() const;

    private:
        GLFWwindow *window;
        double dt{};
    };
}

#endif //MINI_MARIO_GAME_APP_H
