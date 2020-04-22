#include "controller.h"
#include "game.h"
#include "gameobject.h"
#include "renderer.h"
#include <iostream>

int main(int argc, char *argv[]) {
    constexpr std::size_t kFramesPerSecond{100};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{800};
    constexpr std::size_t kScreenHeight{600};
    constexpr std::size_t kGridWidth{60};
    constexpr std::size_t kGridHeight{45};

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    return 0;
}