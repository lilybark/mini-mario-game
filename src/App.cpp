/* date = April 10, 2024 5:17 PM */

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include "App.h"
#include "renderer/RendererController.h"

namespace MiniMario {
    App::App() {
        // initialize GLFW
        if (!glfwInit()) {
            // print error here; for now, exit program
            std::cout << "glfw init fail!" << std::endl;
            exit(-1);
        }

        // TODO: set the error callback to something that works with our logging utils!
        // glfwSetErrorCallback(bla);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(800, 600, "Untitled Window", nullptr, nullptr);
        if (window == nullptr) {
            // error! for now, we exit
            std::cout << "glfw window init fail!" << std::endl;
            exit(-1);
        }

        glfwMakeContextCurrent(window);
        gladLoadGL(glfwGetProcAddress);

        // initialize GL



    }

    void App::run() {
        while (!glfwWindowShouldClose(window)) {
            double startTime = glfwGetTime();
            // gets buffered events, like button presses and window events.
            glfwPollEvents();

            // set background color to black
            glClearColor(0.0, 0.0, 0.0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            //Renderer::RendererController::get()->update(deltaTime());

            // glfw runs with two buffers (to reduce shearing). We swap one and draw to another, afaik.
            glfwSwapBuffers(window);


            double endTime = glfwGetTime();
            dt = endTime - startTime;
        }
    }

    App::~App() {
        // will handle other closing operations later...
        glfwTerminate();
    }

    double App::deltaTime() const {
        return dt;
    }
}