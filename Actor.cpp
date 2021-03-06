#include <raylib.h>

#include "Collision.hpp"
#include "Effect.hpp"
#include "GameUtils.hpp"
#include "Actor.hpp"

#include <iostream>

using namespace GameUtils;

Actor::Actor(Context *ctx){
    this->context = ctx;
}

Actor::~Actor(){

}

void Actor::SetXPos(float x){
    this->x_prev = this->x_pos;
    this->x_pos = x;
}

void Actor::SetYPos(float y){
    this->y_prev = this->y_pos;
    this->y_pos = y;
}

float Actor::GetXPos(){
    return this->x_pos;
}

float Actor::GetXPos_prev(){
    return this->y_prev;
}

float Actor::GetYPos(){
    return this->y_pos;
}

float Actor::GetYPos_prev(){
    return this->y_prev;
}


void Actor::Update(){

};

void Actor::Draw(){
  
};

void Actor::OnCollision(Collision C, Rectangle CollisionData){
    
};

void TestActor::Update(){
    /*
    if(IsKeyDown(KEY_D)){
        velocity_x = 300;
    }
    else if(IsKeyDown(KEY_A)){
        velocity_x = -300;
    }
    else{
        velocity_x = 0;
    }
    */
    if(this->grounded){
        this->context->push_effect(new TextEffect("Grounded", 0, 0, 50, RED, 0));
    }

    this->grounded = false;

    this->SetXPos(this->GetXPos()+this->velocity_x*this->context->frame_delta);
    this->SetYPos(this->GetYPos()+this->velocity_y*this->context->frame_delta);

    this->hitbox = {.x = this->GetXPos(), .y = this->GetYPos(), .width = 20., .height = 20};

    velocity_y += 100*this->context->frame_delta;

};

void TestActor::Draw(){
    DrawRectangle(this->hitbox.x, this->hitbox.y, this->hitbox.width, this->hitbox.height, grounded?RED:BLUE);
};


TestActor::TestActor(Context *ctx):Actor(ctx){
    this->SetYPos(0);
    this->SetXPos(0);
}
TestActor::~TestActor(){}

void TestActor::OnCollision(Collision C, Rectangle CollisionData){
    if(this->hitbox.x < C.hitbox.x) {this->SetXPos(C.hitbox.x - this->hitbox.width); this->velocity_x = 0; }
    else if(this->hitbox.x + this->hitbox.width > C.hitbox.x + C.hitbox.width) {this->SetXPos(C.hitbox.x + C.hitbox.width); this->velocity_x = 0;}

    if(this->hitbox.y < C.hitbox.y) {this->SetYPos(C.hitbox.y - this->hitbox.height); this->velocity_y = 0; this->grounded = true;}
    else if(this->hitbox.y + this->hitbox.height > C.hitbox.y + C.hitbox.height) {this->SetYPos(C.hitbox.y + C.hitbox.height); this->velocity_y = 0;}

    
}