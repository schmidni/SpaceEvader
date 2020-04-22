#include "obstacle.h"

#include <cmath>
#include <iostream>

Obstacle::Obstacle(int pos_x, int pos_y, Player &player) {
    _pos_x = pos_x;
    _pos_y = pos_y;

    _player = &player;

    _velocity = {0.1f, 0.0f};

    body.push_back(
        SDL_Point{static_cast<int>(_pos_x), static_cast<int>(_pos_y)});
}

void Obstacle::Update() {
    UpdatePosition();
    CheckCollision();
}

// update all points of the body using the delta from the root point
void Obstacle::UpdateBody() {
    int move_x = static_cast<int>(_pos_x) - body[0].x;
    int move_y = static_cast<int>(_pos_y) - body[0].y;

    for (SDL_Point &p : body) {
        p.x += move_x;
        p.y += move_y;
    }
}

// accelerate with factor
void Obstacle::Accelerate(int f) {
    _velocity[0] *= f;
    _velocity[1] *= f;
}

// set size, positive adds body above, negative adds body below
void Obstacle::SetSize(int s) {
    _size = s;
    body.erase(body.begin() + 1, body.end());
    for (int i = 0; i != s; s > 0 ? ++i : --i) {
        body.push_back(
            SDL_Point{static_cast<int>(_pos_x), static_cast<int>(_pos_y + i)});
    }
}

// check for collision with player, if collision detected set player alive false
void Obstacle::CheckCollision() {
    int p_x = _player->body[0].x;
    int p_y = _player->body[0].y;

    for (SDL_Point b : body) {
        if (b.x == p_x && b.y == p_y) {
            _player->alive = false;
        }
    }
}