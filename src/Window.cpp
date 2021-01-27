#include "GameEngine/Exceptions.hpp"
#include "GameEngine/Window.hpp"

#include <iostream>

using namespace GameEngine;

Window::Window() : Window("GameEngine") { }
Window::Window(std::string title) : Window(title, 800, 600) { }
Window::Window(std::string title, unsigned int width, unsigned int height) 
    : title(title), width(width), height(height), color(0.6f, 0.89f, 1.0f, 1.0f)
{
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        throw WindowException("Failed to create window '" + title + "'");
    }

    glfwMakeContextCurrent(window);
    
    glClearColor(color.r, color.g, color.b, color.a);
}

Window::~Window() {
    if (window) {
        glfwDestroyWindow(window);
    }
}