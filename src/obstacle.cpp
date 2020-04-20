#include "obstacle.h"

#include <cmath>
#include <iostream>

Obstacle::Obstacle(int pos_x, int pos_y){
    _pos_x = pos_x;
    _pos_y = pos_y;

    _velocity = {0.0f, 0.0f};

    body.push_back(SDL_Point{static_cast<int>(_pos_x), static_cast<int>(_pos_y) });
}

void Obstacle::Update(){}

void Obstacle::Accelerate(){}