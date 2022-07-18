#include "raylib.h"

#include "Collision.hpp"
#include "GameUtils.hpp"

void Collision::Draw(){
    DrawRectangle(this->hitbox.x, this->hitbox.y, this->hitbox.width, this->hitbox.height, ORANGE);
}

Collision::Collision(){
    this->hitbox = { .x = 0, .y = (float)GameUtils::Config::window_height/2, .width = 720, .height = 500,};
}

Collision::Collision(Rectangle hitbox){
 this->hitbox = hitbox;
}

Collision::~Collision(){};