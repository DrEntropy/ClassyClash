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
    velocity= Vector2Subtract(target->getScreenPos(),getScreenPos());
  
   


   // rest of update
   BaseCharacter::tick(deltaTime);

   // Check to see if we can bite the knight! 
   if( CheckCollisionRecs(target->getCollisionRect(),getCollisionRect()) ){
        target->takeDamage(damagePerSec*deltaTime);
   }
    

}


// compute screen position using known fact that target is in center.

Vector2 Enemy::getScreenPos() {
    return Vector2Subtract(worldPos,target->getWorldPos());}



