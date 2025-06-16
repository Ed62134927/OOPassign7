#ifndef Bb_H
#define Bb_H

#include "collider.h"
#include "gameObject.h"
#include "unit.h"



class Bomb : public GameObject, public ICollider {

public:
  void update() override;
  void onCollision(ICollider *other) override;
  bool intersect(ICollider *other) override;
  void edgeCollision() override;
  
  void setpower(int power) {
    _power = power;
  }
  int getpower() const {
    return _power;
  }
  int gettimer() const {
    return _timer;
  }
  ~Bomb() override = default;

  


protected:
  int _timer=7;
  int _power=1;
};
#endif