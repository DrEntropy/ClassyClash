
#include "raylib.h"

#include "Character.h"
#include "raymath.h"

 





 

void Character::tick(float deltaTime) {

    // update worldpos, save previous
    worldPosLastFrame = worldPos;
   

    

    if(IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if(IsKeyDown(KEY_D)) velocity.x += 1.0;
    if(IsKeyDown(KEY_W)) velocity.y -= 1.0;
    if(IsKeyDown(KEY_S)) velocity.y += 1.0;
    
 

   //rest of update
   BaseCharacter::tick(deltaTime);


}

 
