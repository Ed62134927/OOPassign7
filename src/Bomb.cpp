#include "Bomb.h"
#include "BombFactory.h"
#include "iconFactory.h"
#include "icon.h"
#include "environment.h"



void Bomb::update() {
    _timer--;
   
}

void Bomb::onCollision(ICollider *other) {
        int a=0;
}


bool Bomb::intersect(ICollider *other) {
    GameObject *otherObj = dynamic_cast<GameObject *>(other);
    if (otherObj) {
        int cor1=_pos.e1;
        int cor2=_pos.e2;
        int cor3=_pos.e2+ icon_height(_icon) ;
        int cor4=_pos.e1+ icon_width(_icon);
        int leftA   = _pos.e1 - _power;
        int rightA  = _pos.e1 + icon_width(_icon) + _power;
        int topA    = _pos.e2 - _power;
      
        int bottomA = _pos.e2 + icon_height(_icon) + _power;

        int leftB   = otherObj->getPosition().e1;
        int rightB  = otherObj->getPosition().e1 + icon_width(otherObj->getIcon());
        int topB    = otherObj->getPosition().e2;
        int bottomB = otherObj->getPosition().e2 + icon_height(otherObj->getIcon());

        // 完全包住才算碰撞
        return (leftB >= leftA && rightB <= rightA &&
                topB >= topA && bottomB <= bottomA)&&((leftB>=cor1&&rightB<=cor4)||(bottomB<=cor3&&topB>=cor2));
    }
    return false;
}

void Bomb::edgeCollision() {
    int a=0;
}

