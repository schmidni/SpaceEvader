#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "obstacle.h"
#include "player.h"
#include "renderer.h"

#include <random>
#include <vector>
#include <future>

class Game {
  public:
    Game(std::size_t grid_width, std::size_t grid_height);

    void Run(Controller const &controller, Renderer &renderer,
             std::size_t target_frame_duration);

    int GetScore() const { return score; };

  private:
    Player player;
    std::vector<Obstacle> obstacles;
    std::vector<std::future<void>> futures;

    int grid_width;
    int grid_height;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};
    float spawnInterval{2000};
    float accelerationInterval{5000};
    float accelerationFactor{1.1};

    Obstacle CreateObstacle();

    void Update();
};

#endif