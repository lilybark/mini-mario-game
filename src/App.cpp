/* date = April 10, 2024 5:17 PM */

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <cmath>
#include <thread>
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

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(800, 600, "Untitled Window", nullptr, nullptr);
        if (window == nullptr) {
            // error! for now, we exit
            std::cout << "glfw window init fail!" << std::endl;
            exit(-1);
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        gladLoadGL(glfwGetProcAddress);

        // initialize GL
        Renderer::RendererController::get();

    }

    void App::run() {
        while (!glfwWindowShouldClose(window)) {
            // gets buffered events, like button presses and window events.
            double startTime = glfwGetTime();

            glfwPollEvents();


            Renderer::RendererController::get()->update(deltaTime());

            // glfw runs with two buffers (to reduce shearing). We swap one and draw to another, afaik.
            glfwSwapBuffers(window);
            // set background color to black
            glClearColor(0.0, 0.0, 0.0, 0.0);
            glClear(GL_COLOR_BUFFER_BIT);

            double endTime = glfwGetTime();
            dt = endTime - startTime;

            //std::cout << dt << std::endl << std::flush;
        }
    }

    App::~App() {
        // will handle other closing operations later...
        glLinkProgram(0);
        glfwTerminate();
    }

    double App::deltaTime() const {
        return dt;
    }
}