#include "raylib.h"
#include "raymath.h"


class Character {

    public:
        Vector2 getWorldPos() {return worldPos;}


    private:
        Texture2D texture;
        Texture2D idle;
        Texture2D run;
        // position
        Vector2 screenPos;
        Vector2 worldPos; 


        // animation variables

        float rightLeft{1.0f};  // -1 left, 1 right. used to flip scale
        float runningTime{};
        int frame{};
        const int maxFrames{6};
        const float updateTime{1.f/12.f};


};

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    float speed{4.0};

// Load in the character textures
    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    Texture2D knight_current=knight_idle;

    Vector2 knightPos {
        (float)windowWidth/2.0f - 4.0f*(0.5f*(float)knight_idle.width/6.0f),

        (float)windowHeight/2.0f - 4.0f* (0.5f*(float)knight_idle.height)
    };
    


    // Animation stuff

    float rightLeft{1.0f};  // -1 left, 1 right. used to flip scale
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f/12.f};


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};

        if(IsKeyDown(KEY_A)) direction.x -= 1.0;
        if(IsKeyDown(KEY_D)) direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S)) direction.y += 1.0;
        
        if(Vector2Length(direction)!=0.0)
        {
          // set mapPos = mapPos - direction
          mapPos = Vector2Subtract(mapPos,
                    Vector2Scale(Vector2Normalize(direction),speed));
          rightLeft = (direction.x < 0.f ? -1.f : 1.f);
          knight_current=knight_run;
        } else {
            knight_current=knight_idle;
        }
        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
       


        // update animation frame
        runningTime += GetFrameTime();
        if(runningTime>updateTime){
            runningTime=0;
            frame++;
            if(frame >= maxFrames)
                frame =0;
        }

        // draw the character
        
        float knightWidth = (float)knight_current.width/6.0f;
        Rectangle source { frame*knightWidth,0.0f, 
            rightLeft * knightWidth,
            (float)knight_current.height
             } ;

        Rectangle dest{ knightPos.x, dest.y = knightPos.y,
             4.0f*knightWidth,
             4.0f*source.height
             };

        DrawTexturePro(knight_current,source,dest,{0,0},0.0f,WHITE);


        EndDrawing();
    }
    CloseWindow();
}