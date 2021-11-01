#pragma once

#include "raylib.h"

class BaseCharacter
{
  public:
         // constructs a character with starting worldPos os and the given textures. 
        BaseCharacter(Vector2 pos,Texture2D idlesprite,Texture2D runsprite,float scale):worldPos{pos},
          idle(idlesprite),run(runsprite),scale(scale) {
              // start in idle.
              texture = idle;
              width = static_cast<float>(texture.width/maxFrames);
              height = static_cast<float>(texture.height);
               
        }

        ~BaseCharacter(){
          UnloadTexture(idle);
          UnloadTexture(run);

        }
        
        // this is abit of a hack.
        // void udpateScreenPos(Vector2 knightPos);

        // returns the world pos of teh character
        inline Vector2 getWorldPos() {return worldPos;}

        // subclasses have to define this.
        virtual Vector2 getScreenPos()=0;

        // update character. These are virtual 

        virtual void tick(float deltaTime) ;

        // draw teh character
        void Render();
        void undoMove();

        Rectangle getCollisionRect( );


    protected:
        Vector2 worldPos{0.f,0.f}; 
        Texture2D texture;
        Texture2D idle;
        Texture2D run;
 
      // speed is  a magic number
        float speed{4.0f};
        float scale{};


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

        Vector2 velocity{};


};