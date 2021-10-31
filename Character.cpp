
#include "raylib.h"

#include "Character.h"
#include "raymath.h"


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


