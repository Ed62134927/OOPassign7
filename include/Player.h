#ifndef RPS_H
#define RPS_H

#include "collider.h"
#include "gameObject.h"
#include "unit.h"
#include <string>

struct Direction {
  int x;
  int y;
};

class Player : public GameObject, public ICollider {

public:
  void update() override;
  void move(int x, int y) {
    _pos.e1 += x;
    _pos.e2 += y;
  }

  void onCollision(ICollider *other) override;
  bool intersect(ICollider *other) override;
  void edgeCollision() override;
  void setDirection(int x, int y) {
    _dir.x = x;
    _dir.y = y;
  }
  void setcontrol(bool control) { _iscontrol = control; }
  void setSpeed(int s) { speed++; }
  bool getcontrol() const { return _iscontrol; }
  Direction getDirection() const { return _dir; }
  int getSpeed() const { return speed; }
  int getLives() const { return lives; }

  void delives() {
    if (lives > 0) {
      lives--;
    }
  }

  void pluspower() { playerpower++; }

  int getpower() const { return playerpower; }

  std::string getName() const { return name; }
  ~Player() override = default;

protected:
  int _iscontrol = 0;
  Direction _dir;
  int speed = 1;
  int lives;
  int playerpower = 1;

  std::string name;
};
#endif