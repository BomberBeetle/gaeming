#include <iostream>
#include <string>
#include <vector>

#include <raylib.h>

#include "GameUtils.hpp"
#include "Actor.hpp"
#include "Collision.hpp"
#include "Effect.hpp"

using namespace GameUtils;

int main(int argc, char* argv[]){

    InitWindow(Config::window_width, Config::window_height, "Test-icles");

    SetTargetFPS(60);  

    std::vector<Actor *> actors = {};

    std::vector<Collision *> geometry = {new Collision()};

    std::vector<Effect *>effects = {};

    std::vector<Effect *>::iterator fx_iter;

    Context* ctx = new Context(&effects);



    Actor* a = new TestActor(ctx);

    actors.push_back(a);

    while(!WindowShouldClose()){
        //Actor update code
        for(Actor* actor:actors){
            actor->Update();
        }

        //Actor collision code
        for(Actor* actor:actors){
            for(Collision* col:geometry){
                if(CheckCollisionRecs(actor->hitbox, col->hitbox)){
                    actor->OnCollision(*col, GetCollisionRec(actor->hitbox, col->hitbox));
                }
            }
        }


        //Draw code
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for(Collision* col: geometry){
                col->Draw();
            }

            for(Actor* actor: actors){
                a->Draw();
            }

            for(Effect* effect: effects){
                effect->Draw();
            }

        EndDrawing();

        

        //Effect update code;
        
        fx_iter = effects.begin();
        while(fx_iter != effects.end()){

            (*fx_iter)->despawn_counter--;
            if((*fx_iter)->despawn_counter < 1){
                fx_iter = effects.erase(fx_iter);
            }
            else{
                ++fx_iter;
            }
        }

        DrawText(std::to_string(effects.size()).c_str(), 0, 0, 20, RED);
    }
}