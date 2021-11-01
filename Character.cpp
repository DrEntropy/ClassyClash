
#include "raylib.h"

#include "Character.h"
#include "raymath.h"

 





 

void Character::tick(float deltaTime) {

    // update worldpos, save previous
    worldPosLastFrame = worldPos;
   

    Vector2 direction{};

    if(IsKeyDown(KEY_A)) direction.x -= 1.0;
    if(IsKeyDown(KEY_D)) direction.x += 1.0;
    if(IsKeyDown(KEY_W)) direction.y -= 1.0;
    if(IsKeyDown(KEY_S)) direction.y += 1.0;
    
    if(Vector2Length(direction)!=0.0)
        {
            // set worldPos = mapPos + direction
            worldPos = Vector2Add(worldPos,
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

void Character::Render(){
                // draw the character

       
        Rectangle source { frame*width,0.0f, 
            rightLeft * width,
            height
            } ;

        Rectangle dest{ screenPos.x, dest.y = screenPos.y,
            scale*width,
            scale*height
            };

        DrawTexturePro(texture,source,dest,{0,0},0.0f,WHITE);

}


