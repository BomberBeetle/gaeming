#ifndef H_ACTOR
#define H_ACTOR

#include <raylib.h>

#include "Collision.hpp"
#include "GameUtils.hpp"

using namespace GameUtils;

class Actor{
    public:
        Actor(Context *);
        ~Actor();
        virtual void Draw();
        virtual void Update();
        virtual void OnCollision(Collision C, Rectangle CollisionData);
        float GetYPos();
        float GetXPos();
        float GetXPos_prev();
        float GetYPos_prev();
        void SetYPos(float);
        void SetXPos(float);
        Context* context;
        Rectangle hitbox;
    private:
        float x_pos;
        float y_pos;
        float x_prev;
        float y_prev;
};
class TestActor: public Actor{
    public:
        TestActor(Context *);
        ~TestActor();
        void Draw();
        void Update();
        void OnCollision(Collision C, Rectangle CollisionData);
        float velocity_x;
        float velocity_y;

};
#endif