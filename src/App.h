/* date = April 07, 2024 4:02 PM */

#ifndef MINI_MARIO_GAME_APP_H
#define MINI_MARIO_GAME_APP_H

#include <GLFW/glfw3.h>
#include <string>

namespace MiniMario {
    //forward decl
    class Scene;

    /**
     * # App
     *
     * This class handles the initialization of the program, the main window, and any button/mouse inputs from the user.
     * It's major backing is in GLFW.
     *
     */
    class App {
    public:
        /**
         * Closes MiniMario, freeing any files or handles.
         */
        ~App();
        /**
         * Spins up the App, causing it to enter the game loop.
         */
        void run();

        int getWidth() const {
            return width;
        }

        int getHeight() const {
            return height;
        }

        /**
         * Gets a pointer to the App instance.
         * @return App singleton
         */
        static App *get();

        /**
         * Gets the change in time since the last update frame.
         */
        double deltaTime() const;

        /**
         * Sets the current scene, closing currently active scene.
         * @param s Pointer to valid scene instance.
         */
        void setScene(Scene *s);
    private:
        /**
         * Starts the MiniMario App, initializing primary window.
         */
        App();
        static App *_inst;

        GLFWwindow *window;
        Scene *scene;
        std::string title{};
        double dt{};
        double runtime{};
        int width, height;
    };
}

#endif //MINI_MARIO_GAME_APP_H
