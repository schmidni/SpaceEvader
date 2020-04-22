#include "gameobject.h"
#include <iostream>

// Set color of object
void GameObject::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    _color[0] = r;
    _color[1] = g;
    _color[2] = b;
    _color[3] = a;
}

// Set 2d velocity vector
void GameObject::SetVelocity(float x, float y) {
    _velocity[0] = x;
    _velocity[1] = y;
}

// Update root position and call update body function
void GameObject::UpdatePosition() {
    _pos_x -= _velocity[0];
    _pos_y -= _velocity[1];
    UpdateBody();
}