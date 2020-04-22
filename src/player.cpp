#include "player.h"
#include <cmath>
#include <iostream>

Player::Player(int grid_width, int grid_height, float pos_x, float pos_y){
    _grid_height = grid_height;
    _grid_width = grid_width;
    _pos_x = pos_x;
    _pos_y = pos_y;

    _velocity = {0.0f, 0.0f};

    body.push_back(SDL_Point{0,0});
}

void Player::Update() {
    float dir_y = GetVelocity()[1];

    switch (direction) {
    case Direction::kNone:
        break;
    case Direction::kUp:
        if (dir_y >= 0)
            Accelerate(Direction::kUp);
        else 
            Decelerate();
        break;
    case Direction::kDown:
        if (dir_y <= 0)
            Accelerate(Direction::kDown);
        else 
            Decelerate();
        break;
    }

    UpdatePosition();
    
    // Wrap the Player around to the beginning if going off of the screen.
    _pos_x = fmod(_pos_x + _grid_width, _grid_width);
    _pos_y = fmod(_pos_y + _grid_height, _grid_height);

    UpdateBody();
}

void Player::UpdateBody(){
    SDL_Point player = {static_cast<int>(_pos_x), static_cast<int>(_pos_y) };
    body[0] = player;
}

void Player::Accelerate(Direction dir){
    float v = std::abs(_velocity[1]);

    if (v == 0 && dir == Direction::kUp)
        _velocity[1] += 0.075;
    if (v == 0 && dir == Direction::kDown)
        _velocity[1] -= 0.075;
    if ( v <= 0.5 )
        _velocity[1] += _velocity[1]*0.2;
}

void Player::Decelerate(){
    _velocity[1] = 0;
}