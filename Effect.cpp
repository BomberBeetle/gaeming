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

TextEffect::TextEffect(char* text, int x, int y, int size, Color color, int duration){
    this->text = text;
    this->x = x;
    this->y = y;
    this->size = size;
    this->color = color;
    this->despawn_counter = duration;
}

void TextEffect::Draw(){
    DrawText(this->text, this->x, this->y, this->size, this->color);
}

TextEffect::~TextEffect(){};
RectDisplay::~RectDisplay(){};
Effect::~Effect(){};