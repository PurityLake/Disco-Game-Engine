#pragma once

#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#include <GLFW/glfw3.h>

#include "Window.hpp"

namespace GameEngine {
    class Game {
    private:
        std::unique_ptr<Window> window;
        std::chrono::time_point<std::chrono::high_resolution_clock> lastTick;

    public:
        Game();
        explicit Game(std::string title);
        Game(std::string title, unsigned int windowWidth, unsigned int windowHeight);

        virtual ~Game();

        virtual void Run();
        virtual void Render(double delta);
        virtual void Update(double delta);

    protected:
        void Setup(std::string title, unsigned int windowWidth, unsigned int windowHeight);
    };
}

#define RUN_BEGIN                                                                               \
    lastTick = std::chrono::high_resolution_clock::now();                                       \
    window->Clear();                                                                            \
    glViewport(0, 0, window->Width(), window->Height());                                        \
    while (!window->ShouldQuit()) {                                                             \
        double delta = 1.0;                                                                     \
        do {                                                                                    \
            auto newTick = std::chrono::high_resolution_clock::now();                           \
            std::chrono::duration<double> diff {                                                \
                std::chrono::duration_cast<std::chrono::milliseconds>(newTick  - lastTick)      \
            };                                                                                  \
            delta = diff.count();                                                               \
            lastTick = newTick;                                                                 \
        } while(0)

#define RUN_END                                                 \
        glfwPollEvents();                                       \
    }
