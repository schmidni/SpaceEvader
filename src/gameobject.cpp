#include "gameobject.h"
#include <iostream>

void GameObject::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    _color[0] = r;
    _color[1] = g;
    _color[2] = b;
    _color[3] = a;
}

void GameObject::SetVelocity(float x, float y) {
    _velocity[0] = x;
    _velocity[1] = y;
}

void GameObject::UpdatePosition() {
    _pos_x -= _velocity[0];
    _pos_y -= _velocity[1];
    UpdateBody();
}