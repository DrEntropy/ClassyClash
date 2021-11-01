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