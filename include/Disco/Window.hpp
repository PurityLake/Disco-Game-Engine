#pragma once

#include <string>

#include <GLFW/glfw3.h>

#include "Disco/Color.hpp"
#include "Disco/Exceptions.hpp"

namespace Disco {
    class Window {
    private:
        GLFWwindow *window;
        std::string title;
        unsigned int width, height;
        RGBA color;

    public:
        Window();
        Window(std::string title);
        Window(std::string title, unsigned int width, unsigned int height);

        ~Window();

        void SetColor(RGBA rgba) {
            color = rgba;
            glClearColor(color.r, color.g, color.b, color.a);
        }

        void Update() const {
            glfwSwapBuffers(window);
        }

        void Clear() const {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        bool ShouldQuit() {
            return glfwWindowShouldClose(window);
        } 

        inline unsigned int Width() const {
            return width;
        }

        inline unsigned int Height() const {
            return height;
        }
    };
}