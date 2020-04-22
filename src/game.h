#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "obstacle.h"
#include "player.h"
#include "renderer.h"

#include <future>
#include <random>
#include <vector>

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
    float spawnInterval{2000};         // spawn obstacle every x ms
    float spawnFactor{1.2};            // decrease spawn inverval with time
    float accelerationInterval{20000}; // accelerate game every x ms
    float accelerationFactor{1.3};     // accelerate obstacles with time
    int skipSpawns{0}; // break between spawns when game gets accelerated

    Obstacle CreateObstacle();

    void Update();
};

#endif