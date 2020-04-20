#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL.h"
#include "gameobject.h"
#include <vector>

class Obstacle : public GameObject {
  public:
    Obstacle(int pos_x, int pos_y);

    void Update() override;

    void Accelerate(Direction dir) override {};
    void Accelerate();

    void Decelerate() override {};

    int size{1};
    std::vector<SDL_Point> body;
};

#endif