#include "raylib.h"
#include "raymath.h"


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

void Character::setScreenPos(int windowWidth,int windowHeight){
            screenPos = {
                (float)windowWidth/2.f - 4.0f*(0.5f*(float)texture.width/6.0f),
                (float)windowHeight/2.f - 4.0f* (0.5f*(float)texture.height) };

}

void Character::tick(float deltaTime) {

    // update worldpos

    Vector2 direction{};

    if(IsKeyDown(KEY_A)) direction.x -= 1.0;
    if(IsKeyDown(KEY_D)) direction.x += 1.0;
    if(IsKeyDown(KEY_W)) direction.y -= 1.0;
    if(IsKeyDown(KEY_S)) direction.y += 1.0;
    
    if(Vector2Length(direction)!=0.0)
        {
            // set mapPos = mapPos - direction
            worldPos = Vector2Subtract(worldPos,
                        Vector2Scale(Vector2Normalize(direction),speed));
                        
            rightLeft = (direction.x < 0.f ? -1.f : 1.f);
            texture=run;
        } else {
            texture=idle;
        }

    // update animation frame
    runningTime += deltaTime;
    if(runningTime>updateTime){
        runningTime=0;
        frame++;
        if(frame >= maxFrames) frame =0;
    }
    

}

void Character::draw(){
                // draw the character

        float knightWidth = (float)texture.width/6.0f;
        Rectangle source { frame*knightWidth,0.0f, 
            rightLeft * knightWidth,
            (float)texture.height
            } ;

        Rectangle dest{ screenPos.x, dest.y = screenPos.y,
            4.0f*knightWidth,
            4.0f*source.height
            };

        DrawTexturePro(texture,source,dest,{0,0},0.0f,WHITE);

}





/// main loop

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    // Vector2 mapPos{0.0, 0.0};
    // float speed{4.0};

    Character knight("characters/knight_idle_spritesheet.png",
                    "characters/knight_run_spritesheet.png");
    knight.setScreenPos(windowWidth,windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        knight.tick(GetFrameTime());

        // draw the map
        DrawTextureEx(map, knight.getWorldPos(), 0.0, 4.0, WHITE);
       

        knight.draw();


        EndDrawing();
    }
    CloseWindow();
}