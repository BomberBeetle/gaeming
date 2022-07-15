#include <raylib.h>

#include "Collision.hpp"
#include "Effect.hpp"
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
};


TestActor::TestActor(Context *ctx){
    y_pos = 0;
    x_pos = 0;
    this->context = ctx;
}
TestActor::~TestActor(){}

void TestActor::OnCollision(Collision C, Rectangle CollisionData){
    this->context->push_effect(new RectDisplay(CollisionData));
}