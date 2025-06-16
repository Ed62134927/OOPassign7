// TODO implementation
//
//
//
#include "gameObject.h"


Position GameObject::getPosition() const {
	return _pos;
}

Icon GameObject::getIcon() const {
	return _icon;
}

bool GameObject::getactive() const {
	return _isactive;
}
void GameObject::update() {
	int a=0;

}

void GameObject::setactive(bool con) {
	_isactive=con;
}
