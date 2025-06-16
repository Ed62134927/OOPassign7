#ifndef PLACEFACTORY_H
#define PLACEFACTORY_H

#include "gameObject.h"
#include "PlaceObj.h"
#include "unit.h"
#include "icon.h"

class object3 : public PlaceObject{
	friend class PlaceobjFactory;
	public:
		object3(Position pos, Icon icon, bool destruct,PLSType type,int time);
	    void update() override;

};

class PlaceobjFactory{
	public:
		static GameObject* createObject(Position pos, Icon icon, bool destruct,PLSType type,int time);
		
		
};


#endif