#ifndef PLS_H
#define PLS_H

#include "Player.h"
#include "collider.h"
#include "gameObject.h"
#include "unit.h"

enum PLSType { ROCK, TREE, GRASS, FIRE, SAND, FIREMOUNT, POWER };

class PlaceObject : public GameObject, public ICollider {

public:
  void update() override;
  void onCollision(ICollider *other) override;
  bool intersect(ICollider *other) override;
  void edgeCollision() override;
  int funtion(GameObject *&obj);

  ~PlaceObject() override = default;
  PLSType getType() const { return _type; }
  int getTime() const { return time; }
  void setTime(int t) { time = t; }

protected:
  int _isDestruct;
  PLSType _type;
  int time;
};
#endif