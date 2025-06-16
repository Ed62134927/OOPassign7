#include "PlaceObj.h"
#include "PlaceobjFactory.h"
#include "environment.h"
#include "icon.h"
#include "iconFactory.h"

void PlaceObject::update() { time--; }

void PlaceObject::onCollision(ICollider *other) { int a = 0; }

int PlaceObject::funtion(GameObject *&obj) {
  Player *player = dynamic_cast<Player *>(obj);
  if (_type == FIRE) {
    player->delives();
  } else if (_type == POWER) {
    player->pluspower();
    time = 0;
  }
  return 0;
}
bool PlaceObject::intersect(ICollider *other) { return true; }

void PlaceObject::edgeCollision() { int a = 0; }
