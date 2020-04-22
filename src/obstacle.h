#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "SDL.h"
#include "gameobject.h"
#include "player.h"
#include <vector>

class Obstacle : public GameObject {
  public:
    Obstacle(int pos_x, int pos_y, Player &player);

    void Update() override;

    void Accelerate(Direction dir) override{};
    void Accelerate(int f);

    void Decelerate() override{};

    void SetSize(int s);

    std::vector<SDL_Point> body;

  protected:
  private:
    void UpdateBody() override;
    void CheckCollision();
    int _size{1};
    Player *_player;
};

#endif