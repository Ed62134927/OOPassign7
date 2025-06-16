#include "PlaceobjFactory.h"



object3::object3(Position pos, Icon icon, bool destruct,PLSType type,int time){
      this->_pos = pos;
      this->_icon = icon;
      this->_isDestruct = destruct;
      this->_type = type;
      this->_isactive = false;
      this->time = time;
}

void object3::update() {
   int a=0;
}



GameObject* PlaceobjFactory::createObject(Position pos, Icon icon, bool destruct,PLSType type,int time){
     return new object3(pos,icon,destruct,type,time);

}
