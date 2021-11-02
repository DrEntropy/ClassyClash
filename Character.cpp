
#include "raylib.h"

#include "Character.h"
#include "raymath.h"

 



Vector2 Character::getScreenPos() {
    return screenPos;
}

 

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


// draw sword
void Character::drawSword(){
  
  Vector2 origin{};
  Vector2 offset{};
  float rotation;

  if (rightLeft > 0.f){

      origin = {0.f,weapon.height*scale}; // bottom left
      offset = {35.f,55.f};
      rotation = 35.f;
      weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height*scale,
            weapon.width*scale,
            weapon.height*scale
      };

  } else {
      origin = {weapon.width*scale,weapon.height*scale}; // bottom right
      offset = {25.f,55.f};
      rotation = -35.f;
       weaponCollisionRec = {
            getScreenPos().x + offset.x -weapon.width*scale,
            getScreenPos().y + offset.y - weapon.height*scale,
            weapon.width*scale,
            weapon.height*scale
      };

  }
  Rectangle source{0.f,0.f,static_cast<float>(weapon.width)*rightLeft,
  static_cast<float>(weapon.height)};
  Rectangle dest{screenPos.x +offset.x,screenPos.y+offset.y,weapon.width*scale,weapon.height*scale};

  DrawTexturePro(weapon,source,dest,origin,rotation,WHITE);
  //DrawRectangleRec(weaponCollisionRec,RED);

}

 
