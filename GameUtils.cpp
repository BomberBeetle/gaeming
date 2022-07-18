#include <vector>
#include "Effect.hpp"
#include "GameUtils.hpp"

namespace GameUtils{

    int Config::window_width = 1280;
    int Config::window_height = 720;
    int Config::target_fps = 60;

    void Context::push_effect(Effect *fx){
        effect_queue->push_back(fx);
    }
    
    Context::Context(std::vector<Effect *> *fxq){
        this->frame_delta = 0;
        this->effect_queue = fxq;
    }

}

