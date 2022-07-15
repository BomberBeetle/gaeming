#include <raylib.h>

#include "GameUtils.hpp"
#include "Actor.hpp"

using namespace GameUtils;

void TestActor::Update(){
    this->x_pos +=5;
    this->y_pos +=5;
    this->hitbox = {.x = (float)x_pos, .y = (float)y_pos, .width = 20, .height = 20};
}

void TestActor::Draw(){
    DrawRectangle(this->hitbox.x, this->hitbox.y, this->hitbox.width, this->hitbox.height, RED);
}

TestActor::TestActor(){
    y_pos = 0;
    x_pos = 0;
}
TestActor::~TestActor(){}