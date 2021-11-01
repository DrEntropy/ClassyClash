#include "Prop.h"
#include "raymath.h"


Prop::Prop(Vector2 pos,Texture2D tex,float pscale):scale(pscale),worldPos{pos},
        texture{tex}
{

   //other stuff
}

void Prop::Render(Vector2 knightPos){
    Vector2 screenPos = Vector2Subtract(worldPos,knightPos);

    DrawTextureEx(texture,screenPos,0.0f,scale,WHITE);
}

Rectangle Prop::getCollisionRect(Vector2 knightPos) {
     Vector2 screenPos = Vector2Subtract(worldPos,knightPos);
     return Rectangle{screenPos.x,screenPos.y,
             texture.width*scale,texture.height*scale};

}