#include "BaseCharacter.h"
#include "raymath.h"

// undo move

 void BaseCharacter::undoMove() {

     worldPos =worldPosLastFrame;
 }

// void BaseCharacter::udpateScreenPos(Vector2 knightPos){
//       screenPos = Vector2Subtract(worldPos,knightPos);
// }  

Rectangle BaseCharacter::getCollisionRect( )  {
         return Rectangle{screenPos.x,screenPos.y,
             width*scale,height*scale};  

}

void BaseCharacter::tick(float deltaTime){
      // move
      if(Vector2Length(velocity)!=0.0)
        {
            // set worldPos = mapPos + direction
            worldPos = Vector2Add(worldPos,
                        Vector2Scale(Vector2Normalize(velocity),speed));
                        
            rightLeft = (velocity.x < 0.f ? -1.f : 1.f);
            texture=run;
        } else {
            texture=idle;
        }
      velocity = {};

      // update animation frame
    runningTime += deltaTime;
    if(runningTime>updateTime){
        runningTime=0;
        frame++;
        if(frame >= maxFrames) frame =0;
    }
    
}

void BaseCharacter::Render(){
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