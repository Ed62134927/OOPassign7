#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "collider.h"
#include "gameObject.h"
#include "view.h"
#include <termios.h>
#include <vector>

class Controller {

public:
  Controller(View &);
  void addPlayer(GameObject *obj);
  void addBomb(GameObject *objs);
  void addPlace(GameObject *objs);
  int run();

private:
  int aiBombCooldown[4] = {10, 10, 10, 10};

  int enemy = 3;
  int playersituation = 1;
  void handleInput(int);
  void update();

  std::vector<GameObject *> _place;
  std::vector<ICollider *> _collider3;
  std::vector<GameObject *> _bomb;
  std::vector<ICollider *> _collider2;

  std::vector<GameObject *> _player;
  std::vector<ICollider *> _collider1;

  // View
  View &_view;
};

static struct termios old_termios, new_termios;
void reset_terminal();
void configure_terminal();
int read_input();

#endif
