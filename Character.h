#pragma once

#include "raylib.h"
#include "BaseCharacter.h"


class Character : public BaseCharacter{

    public:
         
        Character(Texture2D idlesprite,Texture2D runsprite,
                  int windowWidth,int windowHeight,float scale):
          BaseCharacter(Vector2 {0,0},idlesprite,runsprite,scale) {
              // set screen pos to fixed position
              screenPos = {
                static_cast<float>(windowWidth)/2.f - scale*(0.5f*width),
                static_cast<float>(windowHeight)/2.f - scale* (0.5f*height) };
        }

        virtual Vector2 getScreenPos() override;

 
        // update knight 

        virtual void tick(float deltaTime) override;
          
        
   private: 
      // screen pos cache
       Vector2 screenPos;
   


  


};
