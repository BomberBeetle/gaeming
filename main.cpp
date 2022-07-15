#include <iostream>
#include <vector>

#include <raylib.h>

#include "GameUtils.hpp"
#include "Actor.hpp"
#include "Collision.hpp"

using namespace GameUtils;

int main(int argc, char* argv[]){

    InitWindow(Config::window_width, Config::window_height, "Test-icles");

    SetTargetFPS(60);

    Actor* a = new TestActor();
    std::vector<Actor *> actors = {a};

    std::vector<Collision *> geometry = {new Collision()};
    

    while(!WindowShouldClose()){
        //Actor update code
        for(Actor* actor:actors){
            actor->Update();
        }

        //Actor collision code
        for(Actor* actor:actors){
            
        }


        //Draw code
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for(Actor* actor: actors){
                a->Draw();
            }

            for(Collision* col: geometry){
                col->Draw();
            }

        EndDrawing();
    }
}