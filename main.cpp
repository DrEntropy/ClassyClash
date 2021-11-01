

#include "Character.h"
#include "Prop.h"
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

    Character knight{LoadTexture("characters/knight_idle_spritesheet.png"),
                    LoadTexture("characters/knight_run_spritesheet.png"),
                    windowWidth,windowHeight,mapScale};
    
    // props
    
 
    Prop props[2] {
      Prop{Vector2{600.f,300.f},LoadTexture("nature_tileset/Rock.png"),4.f} ,
      Prop{Vector2{400.f,500.f},LoadTexture("nature_tileset/Log.png"),4.f}
    };





    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        knight.tick(GetFrameTime());

        // get position in world, 
         Vector2 worldPos = knight.getWorldPos();
        // verffy still on map
        if (worldPos.x < 0.f ||
           worldPos.y < 0.f ||
            worldPos.x + windowWidth > mapScale*map.width ||
            worldPos.y + windowHeight > mapScale*map.height) 
        {
                knight.undoMove();
                 
        }
        
        // check for collision
        for (auto prop:props) {
           bool coll = CheckCollisionRecs(knight.getCollisionRect(),prop.getCollisionRect(knight.getWorldPos()));
           if(coll) knight.undoMove();
        }
         
          // update world pos
        worldPos = knight.getWorldPos();

      
        Vector2 mapPos = Vector2Scale(worldPos,-1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        knight.Render();
  
        /// DRAW props
        for(auto prop : props){
           prop.Render(worldPos);
        }
        


        EndDrawing();
    }
    CloseWindow();
}