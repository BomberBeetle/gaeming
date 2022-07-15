#pragma once

#include <vector>
#include "Effect.hpp"

namespace GameUtils{
    class Config{
        public:
            static int window_height;
            static int window_width;
    };
    class Context{
        private:
            std::vector<Effect *> *effect_queue;
        public:
            void push_effect(Effect *);
            Context(std::vector<Effect *> *);
    };
}