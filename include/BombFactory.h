// TODO 
// Finish the declaration of GameObjectFactory that
// 1. offers some methods to create a GameObject.
// 2. encapsulates the constructor from the caller. 

#ifndef BOMBFACTORY_H
#define BOMBJECTFACTORY_H

#include "gameObject.h"
#include "Bomb.h"
#include "unit.h"
#include "icon.h"

class object2 : public Bomb{
	friend class GameObjectFactory;
	public:
		object2(Position pos, Icon icon,int power);
	    void update() override;

};

class BombFactory{
	public:
		static GameObject* createObject(Position pos, Icon icon,int power);
		
		
};


#endif