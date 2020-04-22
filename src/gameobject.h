#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include <cmath>
#include <vector>

enum class Direction { kNone, kUp, kDown, kLeft, kRight };

class GameObject {
  public:
    void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    std::vector<Uint8> GetColor() { return _color; };

    void SetVelocity(float x, float y);
    std::vector<float> GetVelocity() { return _velocity; };

    virtual void Accelerate(Direction dir) = 0;
    virtual void Decelerate() = 0;

    virtual void Update() = 0;

    std::vector<SDL_Point> body;

  protected:
    std::vector<Uint8> _color{0xFF, 0xFF, 0xFF, 0xFF};
    std::vector<float> _velocity;

    void UpdatePosition();
    virtual void UpdateBody() = 0;
    
    float _pos_x, _pos_y;
};

#endif