#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"
#include "gameobject.h"

class Player : public GameObject {
 public:
  Player(int grid_width, int grid_height, float pos_x, float pos_y);

  void Update() override;

  void Accelerate(Direction dir) override;
  void Decelerate() override;

  bool PlayerCell(int x, int y);

  Direction direction = Direction::kNone;

  bool alive{true};
  std::vector<SDL_Point> body;
};

#endif