#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy  : public BaseCharacter { 

public:
         
       Enemy(Vector2 pos,Texture2D idlesprite,Texture2D runsprite,float scale): BaseCharacter(pos,idlesprite,runsprite,scale) {
                speed = 0.0f; // slow down the enemy
        }

        // ~Enemy(){
        //   UnloadTexture(idle);
        //   UnloadTexture(run);

        // }

 
        void setTarget(Character*);
        virtual void tick(float deltaTime) override;

private: 
     Character* target;       
       
    

};