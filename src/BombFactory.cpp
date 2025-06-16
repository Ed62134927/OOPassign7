
// TODO implementation
//

#include "BombFactory.h"



object2::object2(Position pos, Icon icon,int power){
      this->_pos = pos;
      this->_icon = icon;
      this->_isactive = false;
      this->_power = power;
     
}

void object2::update() {
   _timer--;
   
}


GameObject* BombFactory::createObject(Position pos, Icon icon,int power){
     return new object2(pos,icon,power);

}
