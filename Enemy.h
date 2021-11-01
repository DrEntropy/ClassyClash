#include "raylib.h"
#include "BaseCharacter.h"

class Enemy  : public BaseCharacter { 

public:
         
       Enemy(Vector2 pos,Texture2D idlesprite,Texture2D runsprite,float scale): BaseCharacter(pos,idlesprite,runsprite,scale) {
               // nothing else to do.
        }

        // ~Enemy(){
        //   UnloadTexture(idle);
        //   UnloadTexture(run);

        // }

 

        void tick(float deltaTime) override;
        void Render(Vector2 knightPos) override;
        Rectangle getCollisionRect(Vector2 knightPos ) override;
    

};