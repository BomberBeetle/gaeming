#include <raylib.h>
class Actor{
    public:
        virtual void Draw() = 0;
        virtual void Update() = 0;
        int x_pos;
        int y_pos;
        Rectangle hitbox;
};
class TestActor: public Actor{
    public:
        TestActor();
        ~TestActor();
        void Draw();
        void Update();
};