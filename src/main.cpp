#include <iostream>
#include <GLFW/glfw3.h>

#include "GameEngine/Game.hpp"

using namespace std;

int main() {
    GameEngine::Game game("GameEngine", 800, 600);

    game.Run();

    return 0;
}
