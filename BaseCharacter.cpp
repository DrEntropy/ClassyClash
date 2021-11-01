#include "BaseCharacter.h"
#include "raymath.h"

// undo move

 void BaseCharacter::undoMove() {

     worldPos =worldPosLastFrame;
 }

void BaseCharacter::udpateScreenPos(Vector2 knightPos){
      screenPos = Vector2Subtract(worldPos,knightPos);
}  

Rectangle BaseCharacter::getCollisionRect( )  {
         return Rectangle{screenPos.x,screenPos.y,
             texture.width*scale,texture.height*scale};  

}