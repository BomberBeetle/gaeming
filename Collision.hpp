#pragma once

#include <raylib.h>

class Collision{
    public:
        void Draw();
        Rectangle hitbox;
        Collision();
        Collision(Rectangle hitbox);
        ~Collision();
};