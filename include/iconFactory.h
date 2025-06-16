// TODO 
// Finish the declaration of IconFactory that
// 1. offers some methods to create an Icon.
// 2. encapsulates the constructor from the caller. 
//
//
//
#ifndef ICONFACTORY_H
#define ICONFACTORY_H

#include "icon.h"

class IconFactory {
public:

	IconFactory()=default;
	~IconFactory()=default;
	static Icon createIcon(Color color, const std::string& ascii);
};


#endif
