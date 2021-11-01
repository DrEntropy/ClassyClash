

#include "Character.h"
#include "raymath.h"





/// main loop

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    // Vector2 mapPos{0.0, 0.0};
    // float speed{4.0};

    const float mapScale{4.0f};

    Character knight{"characters/knight_idle_spritesheet.png",
                    "characters/knight_run_spritesheet.png",
                    windowWidth,windowHeight,mapScale};
    

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        knight.tick(GetFrameTime());

        // get position in world
        Vector2 worldPos = knight.getWorldPos();
        // verffy still on map
        if (worldPos.x < 0.f ||
            worldPos.y < 0.f ||
            worldPos.x + windowWidth > mapScale*map.width ||
            worldPos.y + windowHeight > mapScale*map.height) 
        {
                knight.undoMove();
                worldPos = knight.getWorldPos();
        }



        // flip world pos
        Vector2 mapPos = Vector2Scale(worldPos,-1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
       Prop.h
       

        knight.draw();


        EndDrawing();
    }
    CloseWindow();
}