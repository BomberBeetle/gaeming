#pragma once
#include <raylib.h>

class Effect{
    public:
    int despawn_counter;
    virtual void Draw() = 0;
    virtual ~Effect();
};

class RectDisplay: public Effect{
    public:
    RectDisplay(Rectangle);
    RectDisplay(Rectangle, Color);
    ~RectDisplay();
    Rectangle rect;
    Color color;
    void Draw();
};