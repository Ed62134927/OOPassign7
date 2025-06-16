
// TODO implementation
//

#include "PlayerFactory.h"



object1::object1(Position pos, Icon icon, Direction dir,int live, std::string name) {
      this->_pos = pos;
      this->_icon = icon;
      this->_isactive = true;
      this->_dir = dir;
      this->lives = live;
      this->name = name;
}

void object1::update() {
   if(_dir.x==1){
      _pos.e1+=1;
   }
   else if(_dir.x==-1){
      _pos.e1-=1;
   }
   if(_dir.y==1){
      _pos.e2+=1;
   }else if(_dir.y==-1){
      _pos.e2-=1;
   }
}



GameObject* PlayerFactory::createObject(Position pos, Icon icon, Direction dir,int live,std::string name) {
     return new object1(pos,icon,dir,live, name);

}
