#pragma once

class Character {

    public:
        // todo, add error checking if file doesnt exist.
        Character(const char* idlesprite,const char* runsprite):
          idle(LoadTexture(idlesprite)),run(LoadTexture(runsprite)) {
              // start in idle.
              texture = idle;
        }

        ~Character(){
          UnloadTexture(idle);
          UnloadTexture(run);

        }


        Vector2 getWorldPos() {return worldPos;}

        void setScreenPos(int windowWidth,int widowHeight);

        // update knight 

        void tick(float deltaTime);
        void draw();


    private:
        Texture2D texture;
        Texture2D idle;
        Texture2D run;
        // position
        Vector2 screenPos{};
        Vector2 worldPos{0.f,0.f}; 

        float speed{4.0f};


        // animation variables

        float rightLeft{1.0f};  // -1 left, 1 right. used to flip scale
        float runningTime{};
        int frame{};
        const int maxFrames{6};
        const float updateTime{1.f/12.f};


};
