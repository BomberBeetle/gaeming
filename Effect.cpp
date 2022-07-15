#include <raylib.h>

#include "Effect.hpp"

void RectDisplay::Draw(){
    DrawRectangle(this->rect.x, this->rect.y, this->rect.width, this->rect.height, this->color);
};

RectDisplay::RectDisplay(Rectangle rect){
    this->rect = rect;
    this->color = GREEN;
    this->despawn_counter = 0;
};

RectDisplay::RectDisplay(Rectangle rect, Color color){
    this->rect = rect;
    this->color = color;
    this->despawn_counter = 0;
};

RectDisplay::~RectDisplay(){};
Effect::~Effect(){};