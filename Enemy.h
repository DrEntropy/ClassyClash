#include "raylib.h"

class Enemy { 

public:
         
        Enemy(Vector2 pos,Texture2D idlesprite,Texture2D runsprite,float scale):worldPos{pos},
          idle(idlesprite),run(runsprite),scale(scale) {
              // start in idle.
              texture = idle;
              width = static_cast<float>(texture.width/maxFrames);
              height = static_cast<float>(texture.height);
               
        }

        ~Enemy(){
          UnloadTexture(idle);
          UnloadTexture(run);

        }


        Vector2 getWorldPos() {return worldPos;}

        // update knight 

        void tick(float deltaTime);
        void Render(Vector2 knightPos);
        void undoMove();

        Rectangle getCollisionRect(Vector2 knightPos );


    private:
        Texture2D texture;
        Texture2D idle;
        Texture2D run;
        // position
        Vector2 screenPos{};
        Vector2 worldPos{0.f,0.f}; 

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


};