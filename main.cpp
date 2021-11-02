

#include "Character.h"
#include "Prop.h"
#include "raymath.h"
#include "Enemy.h"

#include <string>
 




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

    Enemy goblin(Vector2 {20.f,20.f},LoadTexture("characters/goblin_idle_spritesheet.png"),
               LoadTexture("characters/goblin_run_spritesheet.png"),4.0f);

    goblin.setTarget(&knight);

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
        
        // check for collision with props
        for (auto prop:props) {
           bool coll = CheckCollisionRecs(knight.getCollisionRect(),prop.getCollisionRect(knight.getWorldPos()));
           if(coll) knight.undoMove();
        }
         
          // update world pos
        worldPos = knight.getWorldPos();

       // now we can 'tick' the goblin now that the player has his final position
       goblin.tick(GetFrameTime());

        

      
        Vector2 mapPos = Vector2Scale(worldPos,-1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        knight.Render();
        knight.drawSword();
        goblin.Render();
  
        /// DRAW props
        for(auto prop : props){
           prop.Render(worldPos);
        }

        // check if character is alive
        if(!knight.getAlive()) {
          DrawText("Game Over!",55,45,40,RED);
          EndDrawing();
          continue;
        } else {
          //alive
          std::string knightsHealth=  "Health: ";
          knightsHealth.append(std::to_string(static_cast<int>(knight.getHealth())));

          DrawText(knightsHealth.c_str(),55,45,40,RED);
        }

        EndDrawing();

        // check for attack.  Not sure how IsMouseButtonPressed works, i presume it resets a flag after you call it.
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && 
               CheckCollisionRecs(knight.getWeaponCollRect(),goblin.getCollisionRect())) {
           // we got him! 
           goblin.setAlive(false);


        }
    }
    CloseWindow();
}