#include "game.h"
#include "SDL.h"
#include <iostream>
#include <algorithm>
#include <vector>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : player(grid_width, grid_height, grid_width / 4, grid_height / 2),
      engine(dev()), random_w(0, 1),
      random_h(grid_height / 3, 3 * grid_height / 4),
      grid_width(static_cast<int>(grid_width)),
      grid_height(static_cast<int>(grid_height)) {}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 obstacle_timestamp = SDL_GetTicks();
    Uint32 acceleration_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;
    float baseFactor = accelerationFactor;


    while (running) {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, player);
        Update();
        renderer.Render(player, obstacles);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render
        // cycle takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // Update the window title.
        if (frame_end - title_timestamp >= 1000) {
            renderer.UpdateWindowTitle(score, frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // spawn obstacles
        if (frame_end - obstacle_timestamp >= spawnInterval) {
            obstacles.push_back(std::move(CreateObstacle()));
            obstacle_timestamp = frame_end;
        }

        // accelerate game
        if (frame_end - acceleration_timestamp >= accelerationInterval) {
            accelerationFactor *= baseFactor;
            spawnInterval /= baseFactor;
            acceleration_timestamp = frame_end;
            std::cout << "Spawn Interval: " << spawnInterval << " accelerationFactor: " << accelerationFactor << "\n";
        }

        // delay the loop to achieve the correct frame rate.
        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::Update() {
    if (!player.alive)
        return;

    // update player
    player.Update();

    // update Obstacles
    for (Obstacle &obs : obstacles) {
        obs.Update();
    }

    // Asynchronous solution using tasks. However the overhead of creating tasks for
    // updating the obstacles is slower than the synchronous way
    // for (Obstacle &obs : obstacles) {
    //     futures.emplace_back(std::async(&Obstacle::Update, &obs));
    // }
    // std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
    //     ftr.wait();
    // });
    // futures.clear();

    // check if obstacle expired, if so delete and count score up
    if (obstacles.size() > 0 && obstacles[0].body[0].x < 0) {
        obstacles.erase(obstacles.begin());
        score++;
    }
}

Obstacle Game::CreateObstacle() {
    int side = random_w(engine);
    Obstacle go{grid_width, side * grid_height, player};
    int size = side ? (-1 * random_h(engine)) : random_h(engine);
    go.SetSize(size);
    go.Accelerate(accelerationFactor);
    return go;
}