#include "Player.h"
#include "PlayerFactory.h"
#include "iconFactory.h"
#include "icon.h"
#include "environment.h"
#include <cstdlib>



void Player::update() {
    _prev_pos = _pos;
    if (_dir.x == 1) {
        _pos.e1 += speed;
    } else if (_dir.x == -1) {
        _pos.e1 -= speed;
    }
    if (_dir.y == 1) {
        _pos.e2 += speed;
    } else if (_dir.y == -1) {
        _pos.e2 -= speed;
    }
}

void Player::onCollision(ICollider *other) {
    
        Player *otherObj = dynamic_cast<Player *>(other);
        if(otherObj){
         if(otherObj->_dir.x==1&&_dir.y==1){
            otherObj->_dir.x=0;
            otherObj->_dir.y=1;
            _dir.x=1;
            _dir.y=0;
         }else if(otherObj->_dir.x==1&&_dir.y==-1){
            otherObj->_dir.x=0;
            otherObj->_dir.y=-1;
            _dir.x=1;
            _dir.y=0;
         }else if(otherObj->_dir.x==-1&&_dir.y==1){
            otherObj->_dir.x=0;
            otherObj->_dir.y=1;
            _dir.x=-1;
            _dir.y=0;
         }else if(otherObj->_dir.x==-1&&_dir.y==-1){
            otherObj->_dir.x=0;
            otherObj->_dir.y=-1;
            _dir.x=-1;
            _dir.y=0;
         }else if(otherObj->_dir.x==1&&_dir.x==-1){
            otherObj->_dir.x=-1;
            otherObj->_dir.y=0;
            _dir.x=1;
            _dir.y=0;
         }else if(otherObj->_dir.x==-1&&_dir.x==1){
            otherObj->_dir.x=1;
            otherObj->_dir.y=0;
            _dir.x=-1;
            _dir.y=0;
         }else if(otherObj->_dir.y==1&&_dir.x==1){
            otherObj->_dir.x=1;
            otherObj->_dir.y=0;
            _dir.x=0;
            _dir.y=1;
         }else if(otherObj->_dir.y==-1&&_dir.x==1){
            otherObj->_dir.x=1;
            otherObj->_dir.y=0;
            _dir.x=0;
            _dir.y=-1;
         }else if(otherObj->_dir.y==1&&_dir.x==-1){
            otherObj->_dir.x=-1;
            otherObj->_dir.y=0;
            _dir.x=0;
            _dir.y=1;
         }else if(otherObj->_dir.y==-1&&_dir.x==-1){
            otherObj->_dir.x=-1;
            otherObj->_dir.y=0;
            _dir.x=0;
            _dir.y=-1;
         }else if(otherObj->_dir.y==1&&_dir.y==-1){
            otherObj->_dir.x=0;
            otherObj->_dir.y=-1;
            _dir.x=0;
            _dir.y=1;
         }else if(otherObj->_dir.y==-1&&_dir.y==1){
            otherObj->_dir.x=0;
            otherObj->_dir.y=1;
            _dir.x=0;
            _dir.y=-1;
         }else if(_dir.x==1&&otherObj->_dir.y==0&&otherObj->_dir.x==0){
            _dir.y=1;
            _dir.x=0;

         }else if(_dir.x==-1&&otherObj->_dir.y==0&&otherObj->_dir.x==0){
            _dir.y=-1;
            _dir.x=0;
         }else if(_dir.y==1&&otherObj->_dir.y==0&&otherObj->_dir.x==0){
            _dir.x=-1;
            _dir.y=0;
         }else if(_dir.y==-1&&otherObj->_dir.y==0&&otherObj->_dir.x==0){
            _dir.x=1;
            _dir.y=0;
         }
        }else{
            if(_dir.x==1){
               _dir.x=-1;
               update();
               _dir.x=0;
              if(rand() % 3 == 0) {
                  _dir.x = 0;
                  _dir.y = 1; 
               } else if(rand() % 3 == 1) {
                  _dir.x = 0;
                  _dir.y = -1; 
               }else{
                  _dir.x=-1;
               }
            }else if(_dir.x==-1){
               _dir.x=1;
               update();
               _dir.x=0;
               if(rand() % 3 == 0) {
                  _dir.x = 0;
                  _dir.y = 1; 
               } else if(rand() % 3 == 1) {
                   _dir.x = 0;
                   _dir.y = -1; 
               }else{
                  _dir.x=1;
               }
            }else if(_dir.y==1){
               _dir.y=-1;
               update();
               _dir.y=0;
               if(rand() % 3 == 0) {
                  _dir.x = 1; 
                  _dir.y = 0;
               } else if(rand() % 3 == 1) {
                  _dir.x = -1; 
                  _dir.y = 0;
               }else{
                  _dir.y=-1;
               }
            }else if(_dir.y==-1){
               _dir.y=1;
               update();
               _dir.y=0;
               if(rand() % 3 == 0) {
                  _dir.x = 1; 
                   _dir.y = 0;
               } else if(rand() % 3 == 1) {
                  _dir.x = -1; 
                  _dir.y = 0;
               }else{
                  _dir.y=1;
               }
            
             }
         }
    }
               


bool Player::intersect(ICollider *other) {
    GameObject *otherObj = dynamic_cast<GameObject *>(other);
    if (otherObj) {
        int leftA   = _pos.e1;
        int rightA  = _pos.e1 + icon_width(_icon);
        int topA    = _pos.e2;
        int bottomA = _pos.e2 + icon_height(_icon);

       
        int leftB   = otherObj->getPosition().e1;
        int rightB  = otherObj->getPosition().e1 + icon_width(otherObj->getIcon());
        int topB    = otherObj->getPosition().e2;
        int bottomB = otherObj->getPosition().e2 + icon_height(otherObj->getIcon());

      
        return (leftA <rightB && rightA > leftB &&
                 topA < bottomB && bottomA > topB);
    }
    return false;
}

void Player::edgeCollision() {
    if (_pos.e1 < 0) {
        _pos.e1 = 0;
        _dir.x = 1;
    } else if (_pos.e1 + icon_width(_icon) > GAME_WINDOW_WIDTH ) {
        _pos.e1 = GAME_WINDOW_WIDTH - icon_width(_icon);
        _dir.x = -1;
    }
    if (_pos.e2 < 0) {
        _pos.e2 = 0;
        _dir.y = 1;
    } else if (_pos.e2 + icon_height(_icon) > GAME_WINDOW_HEIGHT ) {
        _pos.e2 = GAME_WINDOW_HEIGHT - icon_height(_icon);
        _dir.y = -1;
    }
}

