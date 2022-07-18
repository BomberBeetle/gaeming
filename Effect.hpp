#ifndef H_EFFECT
#define H_EFFECT

#include <raylib.h>

class Effect{
    public:
    float despawn_counter;
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

class TextEffect: public Effect{
    public:
    TextEffect(char*, int, int, int, Color, int);
    ~TextEffect();
    char* text;
    int x;
    int y;
    int size;
    Color color;
    void Draw();
    //DrawText(std::to_string(effects.size()).c_str(), 0, 0, 20, RED);
};

#endif