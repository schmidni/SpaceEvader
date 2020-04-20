#ifndef PLAYER_H
#define PLAYER_H

#include "SDL.h"
#include "gameobject.h"
#include <vector>

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

  private:
    int _grid_height;
    int _grid_width;
    void UpdateBody();
};

#endif