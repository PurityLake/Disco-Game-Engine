#include "GameEngine/Game.hpp"
#include "GameEngine/Exceptions.hpp"

#include <iostream>

using namespace GameEngine;

Game::Game() : Game("Game") { }
Game::Game(std::string title) : Game(title, 800, 600) { }
Game::Game(std::string title, unsigned int windowWidth, unsigned int windowHeight) {
    Setup(title, windowWidth, windowHeight);
}

Game::~Game() {
    window.reset(nullptr);
    glfwTerminate();
}

void Game::Setup(std::string title, unsigned int windowWidth, unsigned int windowHeight) {
    if (!glfwInit()) {
        throw GameEngineException("Failed to initialise GLFW3");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = std::make_unique<Window>(title, windowWidth, windowHeight);
}
void Game::Run() {
    RUN_BEGIN;
        Render(delta);
        Update(delta);
    RUN_END;
}

void Game::Render(double delta) {
    std::cout << delta << '\n';
    window->Clear();
}
void Game::Update(double delta) {
    window->Update();
}