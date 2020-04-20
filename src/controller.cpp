#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "player.h"

void Controller::ChangeDirection(Player &player, Direction input) const {
  player.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Player &player) const {
  SDL_Event e;
  ChangeDirection(player, Direction::kNone);
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(player, Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangeDirection(player, Direction::kDown);
          break;

        case SDLK_LEFT:
          ChangeDirection(player, Direction::kLeft);
          break;

        case SDLK_RIGHT:
          ChangeDirection(player, Direction::kRight);
          break;
      }
    }
  }
}