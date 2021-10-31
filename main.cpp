

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

    Character knight("characters/knight_idle_spritesheet.png",
                    "characters/knight_run_spritesheet.png");
    knight.setScreenPos(windowWidth,windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        knight.tick(GetFrameTime());

        // flip world pos
        Vector2 mapPos = Vector2Scale(knight.getWorldPos(),-1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
       

        knight.draw();


        EndDrawing();
    }
    CloseWindow();
}