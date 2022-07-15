#include <raylib.h>
#include "Collision.hpp"
#include "GameUtils.hpp"

using namespace GameUtils;

class Actor{
    public:
        virtual void Draw() = 0;
        virtual void Update() = 0;
        virtual void OnCollision(Collision C, Rectangle CollisionData) = 0;
        int x_pos;
        int y_pos;
        Context* context;
        Rectangle hitbox;
};
class TestActor: public Actor{
    public:
        TestActor(Context *);
        ~TestActor();
        void Draw();
        void Update();
        void OnCollision(Collision C, Rectangle CollisionData);
};