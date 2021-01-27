#include <iostream>
#include <GLFW/glfw3.h>

#include "Disco/Game.hpp"

using namespace std;

int main() {
    Disco::Game game("Disco", 800, 600);

    game.Run();

    return 0;
}
