#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "unit.h"
#include "icon.h"
#include <iostream>
class GameObject{

public:
    
    Position getPosition() const;
    Icon getIcon() const;
    void setIcon(const Icon& icon){
        _icon = icon;
    }
    bool getactive() const;
    void setactive(bool active);
    virtual void update();
    virtual ~GameObject() = default;
    
protected:

    Position _pos;
    Position _prev_pos;
    Icon _icon;
    bool _isactive;
};

#endif
