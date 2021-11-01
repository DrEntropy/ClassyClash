#include "Enemy.h"
#include "raymath.h"


void Enemy::setTarget(Character* atarget){
    target = atarget;
}

void Enemy::tick(float deltaTime) {

    // update worldpos, save previous
    worldPosLastFrame = worldPos;
   

    Vector2 direction{};
    

    // enemy AI TBD
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
   // update screen position, recalling that the taget is at the center.
   screenPos = Vector2Subtract(worldPos,target->getWorldPos());
   // rest of update
   BaseCharacter::tick(deltaTime);

}

 



