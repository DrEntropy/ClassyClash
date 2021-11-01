#include "Enemy.h"
#include "raymath.h"


void Enemy::setTarget(Character* atarget){
    target = atarget;
}

void Enemy::tick(float deltaTime) {

    // update worldpos, save previous
    worldPosLastFrame = worldPos;
   
     
    Vector2 direction{};
    

    // Enemy AI 
    // Compute toTarget
    Vector2 toTarget= Vector2Subtract(target->getScreenPos(),screenPos);
    // normalize toTarget
    toTarget = Vector2Normalize(toTarget);
    // multiply by speed
    toTarget = Vector2Scale(toTarget,speed);
    //move enemy

    worldPos = Vector2Add(toTarget,worldPos);
    
    // for now
    texture = run;

    rightLeft = (toTarget.x < 0.f ? -1.f : 1.f);

    // if(Vector2Length(direction)!=0.0)
    //     {
    //         // set worldPos = mapPos + direction
    //         worldPos = Vector2Add(worldPos,
    //                     Vector2Scale(Vector2Normalize(direction),speed));
                        
    //         rightLeft = (direction.x < 0.f ? -1.f : 1.f);
    //         texture=run;
    //     } else {
    //         texture=idle;
    //     }
   // update screen position, recalling that the taget is at the center.
   screenPos = Vector2Subtract(worldPos,target->getWorldPos());
   // rest of update
   BaseCharacter::tick(deltaTime);

}

 



