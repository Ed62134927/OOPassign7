// TODO 
// Finish the declaration of GameObjectFactory that
// 1. offers some methods to create a GameObject.
// 2. encapsulates the constructor from the caller. 

#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "gameObject.h"
#include "Player.h"
#include "unit.h"
#include "icon.h"

class object1 : public Player{
	friend class GameObjectFactory;
	public:
		object1(Position pos, Icon icon, Direction dir,int live,std::string name) ;
	    void update() override;

};

class PlayerFactory{
	public:
		static GameObject* createObject(Position pos, Icon icon, Direction dir,int live, std::string name);
		
		
		
		
};


#endif



