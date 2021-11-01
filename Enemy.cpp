#include "Enemy.h"
#include "raymath.h"


void Enemy::setTarget(Character* atarget){
    target = atarget;
}

void Enemy::tick(float deltaTime) {

    // update worldpos, save previous
    worldPosLastFrame = worldPos;
   
    // Enemy AI 
    // Compute (un normalized direction) to target.
    velocity= Vector2Subtract(target->getScreenPos(),screenPos);
  
 


   // rest of update
   BaseCharacter::tick(deltaTime);
    
    // update screen pos
   screenPos = Vector2Subtract(worldPos,target->getWorldPos());
}

 



