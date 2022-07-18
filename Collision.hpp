#ifndef H_COLLISION
#define H_COLLISION

#include <raylib.h>

class Collision{
    public:
        void Draw();
        Rectangle hitbox;
        Collision();
        Collision(Rectangle hitbox);
        ~Collision();
};

#endif