#pragma once

#include "raylib.h"


class Character {

    public:
        // todo, add error checking if file doesnt exist.
        Character(const char* idlesprite,const char* runsprite,
                  int windowWidth,int windowHeight,float scale):
          idle(LoadTexture(idlesprite)),run(LoadTexture(runsprite)) {
              // start in idle.
              texture = idle;
              width = (float)texture.width/maxFrames;
              height = (float)texture.height;
              screenPos = {
                (float)windowWidth/2.f - scale*(0.5f*width),
                (float)windowHeight/2.f - scale* (0.5f*height) };
        }

        ~Character(){
          UnloadTexture(idle);
          UnloadTexture(run);

        }


        Vector2 getWorldPos() {return worldPos;}

        // update knight 

        void tick(float deltaTime);
        void draw(float scale);
        void undoMove();


    private:
        Texture2D texture;
        Texture2D idle;
        Texture2D run;
        // position
        Vector2 screenPos{};
        Vector2 worldPos{0.f,0.f}; 

        float speed{4.0f};


        // 
        Vector2 worldPosLastFrame{};


        // animation variables
        float width;
        float height;
        float rightLeft{1.0f};  // -1 left, 1 right. used to flip scale
        float runningTime{};
        int frame{};
        int maxFrames{6};
        float updateTime{1.f/12.f};


};
