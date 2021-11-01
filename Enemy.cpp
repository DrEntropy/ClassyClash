#include "Enemy.h"
#include "raymath.h"


void Enemy::tick(float deltaTime) {

    // update worldpos, save previous
    worldPosLastFrame = worldPos;
   

    Vector2 direction{};
    
    // switch(GetRandomValue(1,5)) {
    //     case 1: direction.x -= 1.0;break;   
    //     case 2: direction.x += 1.0;break;
    //     case 3: direction.y -= 1.0;break;
    //     case 4: direction.y += 1.0;break;
    //     default: ;


    // }
    
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

void Enemy::Render(Vector2 knightPos){
                // draw the character
        Vector2 screenPos = Vector2Subtract(worldPos,knightPos);

        
       
        Rectangle source { frame*width,0.0f, 
            rightLeft * width,
            height
            } ;

        Rectangle dest{ screenPos.x,   screenPos.y,
            scale*width,
            scale*height
            };

        DrawTexturePro(texture,source,dest,{0,0},0.0f,WHITE);

}




