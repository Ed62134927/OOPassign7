#include <ctime>
#include <iostream>
#include <termios.h>
#include <thread>
#include <unistd.h>

#include "controller.h"
#include "environment.h"

#include "Bomb.h"
#include "BombFactory.h"
#include "PlaceObj.h"
#include "PlaceobjFactory.h"
#include "Player.h"
#include "collider.h"
#include "icon.h"
#include "iconFactory.h"
#include "unit.h"

Controller::Controller(View &view) : _view(view) {}
void Controller::addPlayer(GameObject *obj) {
  _player.push_back(obj);
  ICollider *ob = dynamic_cast<ICollider *>(obj);
  _collider1.push_back(ob);
}

void Controller::addBomb(GameObject *obj) {
  _bomb.push_back(obj);
  ICollider *ob = dynamic_cast<ICollider *>(obj);
  _collider2.push_back(ob);
}
void Controller::addPlace(GameObject *obj) {
  _place.push_back(obj);
  ICollider *ob = dynamic_cast<ICollider *>(obj);
  _collider3.push_back(ob);
}

int Controller::run() {
  // initial setup
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  configure_terminal();

  // init state
  int input = -1;
  clock_t start, end;
  Player *obj = dynamic_cast<Player *>(_player[0]);
  obj->setcontrol(true);

  int controlco = 0;
  int controlnumber = 0;

  // Main loop
  while (true) {
    printf("\033[2J\033[1;1H");
    start = clock();

    input = read_input();

    // ESC to exit program
    if (input == 27)
      break;

    if (controlco == 1) {
      _player[0]->update();
      controlco = 0;
    }
    this->handleInput(input);

    _view.resetLatest();

    //炸彈倒計時
    for (int j = 0; j < _bomb.size(); ++j) {
      _bomb[j]->update();
    }
    // AI 放炸彈條件改成
    if (_player.size() > 1 && enemy > 0 && aiBombCooldown[1] == 0) {
      Position pos = _player[1]->getPosition();

      Icon icon = IconFactory::createIcon(Color::YELLOW, "B");
      Player *player = dynamic_cast<Player *>(_player[1]);
      GameObject *bombobj =
          BombFactory::createObject(pos, icon, player->getpower());
      _bomb.push_back(bombobj);
      ICollider *col = dynamic_cast<ICollider *>(bombobj);
      _collider2.push_back(col);
      aiBombCooldown[1] = 20; // 100 frame 冷卻
    }
    if (_player.size() > 1 && enemy > 1 && aiBombCooldown[2] == 0) {
      Position pos = _player[2]->getPosition();

      Player *player = dynamic_cast<Player *>(_player[2]);
      Icon icon = IconFactory::createIcon(Color::YELLOW, "B");
      GameObject *bombobj =
          BombFactory::createObject(pos, icon, player->getpower());
      _bomb.push_back(bombobj);
      ICollider *col = dynamic_cast<ICollider *>(bombobj);
      _collider2.push_back(col);
      aiBombCooldown[2] = 10; // 不同AI可設不同冷卻
    }
    if (_player.size() > 1 && enemy > 2 && aiBombCooldown[3] == 0) {
      Position pos = _player[3]->getPosition();

      Player *player = dynamic_cast<Player *>(_player[3]);
      Icon icon = IconFactory::createIcon(Color::YELLOW, "B");
      GameObject *bombobj =
          BombFactory::createObject(pos, icon, player->getpower());
      _bomb.push_back(bombobj);
      ICollider *col = dynamic_cast<ICollider *>(bombobj);
      _collider2.push_back(col);
      aiBombCooldown[3] = 30;
    }
    // 先更新所有物件位置
    for (int i = 0; i < _player.size(); ++i) {
      if (i != 0) {
        _player[i]->update();
      }
    }
    for (int i = 1; i <= 3; ++i) {
      if (aiBombCooldown[i] > 0)
        aiBombCooldown[i]--;
    }

    //處理地面物件
    for (int j = 0; j < _place.size(); ++j) {
      _place[j]->update();
    }
    for (int i = 0; i < _place.size(); i++) {
      PlaceObject *placeobj = dynamic_cast<PlaceObject *>(_place[i]);
      if (placeobj->getType() == FIRE || placeobj->getTime() <= 0) {
        delete _place[i];
        _place.erase(_place.begin() + i);
        _collider3.erase(_collider3.begin() + i);
        i--;
      }
    }

    // 檢查邊界碰撞
    for (ICollider *col : _collider1) {
      col->edgeCollision();
    }

    // 檢查物件間碰撞
    bool hasCollision = false;
    // 檢查玩家與地面物件碰撞
    for (int i = 0; i < _collider1.size(); i++) {
      for (int j = 0; j < _collider3.size(); j++) {
        if (_collider1[i]->intersect(_collider3[j])) {
          PlaceObject *placeobj = dynamic_cast<PlaceObject *>(_collider3[j]);
          if (placeobj->getType() == FIRE || placeobj->getType() == POWER) {
            placeobj->funtion(_player[i]);
          } else {
            _collider1[i]->onCollision(_collider3[j]);
            placeobj->funtion(_player[i]);
          }
          hasCollision = true;
          break;
        }
      }
    }
    // 檢查玩家與炸彈碰撞
    for (int i = 0; i < _collider1.size(); i++) {
      for (int j = 0; j < _collider2.size(); j++) {
        if (_collider1[i]->intersect(_collider2[j])) {
          _collider1[i]->onCollision(_collider2[j]);

          if (i == 0) {
            controlco = 1;
            controlnumber = i;
          }
          hasCollision = true;
        }
      }
    }
    // 檢查玩家間碰撞
    for (int i = 0; i < _collider1.size() - 1; i++) {
      for (int j = i + 1; j < _collider1.size(); j++) {
        if (_collider1[i]->intersect(_collider1[j])) {
          _collider1[i]->onCollision(_collider1[j]);
          _player[i]->update();
          _player[j]->update();
          if (i == 0) {
            controlco = 1;
            controlnumber = i;
          }
          hasCollision = true;
        }
      }
    }
    //檢查炸彈爆炸
    for (int i = 0; i < _bomb.size(); i++) {
      Bomb *bomb = dynamic_cast<Bomb *>(_bomb[i]);
      if (bomb->gettimer() <= 0) {
        for (int j = 0; j < _collider1.size(); j++) {
          if (bomb->intersect(_collider1[j])) {
            Player *otherObj = dynamic_cast<Player *>(_collider1[j]);
            otherObj->delives();
            hasCollision = true;
          }
        }
        for (int j = 0; j < _collider3.size(); j++) {
          if (bomb->intersect(_collider3[j])) {
            PlaceObject *otherObj = dynamic_cast<PlaceObject *>(_collider3[j]);
            if (otherObj->getType() == FIRE || otherObj->getType() == POWER)
              continue;

            otherObj->setTime(0);
            if (rand() % 10 < 2) { // 20%
              Position pos = otherObj->getPosition();
              Icon icon = IconFactory::createIcon(Color::NOCHANGE, "+");
              GameObject *powerup =
                  PlaceobjFactory::createObject(pos, icon, true, POWER, 10000);
              _place.push_back(powerup);
              ICollider *col = dynamic_cast<ICollider *>(powerup);
              _collider3.push_back(col);
            }
            hasCollision = true;
          }
        }
        Position center = bomb->getPosition();
        for (int dir = 0; dir < 4; ++dir) { // 上下左右
          for (int p = 0; p <= bomb->getpower(); ++p) {
            Position pos = center;
            if (dir == 0)
              pos.e1 += p; // 右
            if (dir == 1)
              pos.e1 -= p; // 左
            if (dir == 2)
              pos.e2 += p; // 下
            if (dir == 3)
              pos.e2 -= p; // 上
            Icon icon = IconFactory::createIcon(Color::GREEN, " ");
            GameObject *placeobj =
                PlaceobjFactory::createObject(pos, icon, true, FIRE, 1);
            _place.push_back(placeobj);
            ICollider *col = dynamic_cast<ICollider *>(placeobj);
            _collider3.push_back(col);
          }
        }

        delete _bomb[i];
        _bomb.erase(_bomb.begin() + i);
        _collider2.erase(_collider2.begin() + i);
        i--;
      }
    }

    // 如果有碰撞發生，再次檢查邊界
    if (hasCollision) {
      for (ICollider *col : _collider1) {
        col->edgeCollision();
      }
    }
    for (int i = 0; i < _place.size(); i++) {
      PlaceObject *placeobj = dynamic_cast<PlaceObject *>(_place[i]);
      if (placeobj->getTime() <= 0) {
        delete _place[i];
        _place.erase(_place.begin() + i);
        _collider3.erase(_collider3.begin() + i);
        i--;
      }
    }

    // 更新顯示
    for (GameObject *obj : _player) {
      _view.updateGameObject(obj);
    }
    for (GameObject *obj : _bomb) {
      _view.updateGameObject(obj);
    }
    for (GameObject *obj : _place) {
      _view.updateGameObject(obj);
    }
    _view.render();

    //玩家狀態顯示
    for (int i = 0; i < _player.size(); i++) {
      Player *player = dynamic_cast<Player *>(_player[i]);
      std::cout << player->getName() << ":" << player->getLives()
                << " lives, power: " << player->getpower() << std::endl;
    }

    // 檢查遊戲結束條件

    for (int i = _player.size() - 1; i >= 0; i--) {
      Player *player = dynamic_cast<Player *>(_player[i]);
      if (player->getLives() <= 0) {
        std::cout << player->getName() << " is dead!" << std::endl;
        _player.erase(_player.begin() + i);
        _collider1.erase(_collider1.begin() + i);
        if (player->getcontrol()) {
          playersituation = 0;
        } else {
          enemy--;
        }
      }
    }
    int ans;
    int mode;
    if (enemy == 0 && playersituation == 1) {
      std::cout << "Player  wins!" << std::endl;

      break;

    } else if (enemy == 0 && playersituation == 0) {
      std::cout << "Game Over! " << std::endl;

      break;
    } else if (enemy > 0 && playersituation == 0) {
      std::cout << "Game Over! " << std::endl;

      break;
    }

    end = clock();

    // frame rate normalization
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    if (time_taken > SPF)
      continue;
    int frameDelay = int((SPF - time_taken) * 1000);
    if (frameDelay > 0)
      std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay));
  }
  return 0;
}

void Controller::handleInput(int keyInput) {

  // If there is no input, do nothing.
  if (keyInput == -1)
    return;

  if (keyInput == 'b') {
    // TODO
    // handle bomb placement.

    Player *player = dynamic_cast<Player *>(_player[0]);
    Position pos = player->getPosition();
    Icon icon = IconFactory::createIcon(Color::YELLOW, "B");
    GameObject *bomb = BombFactory::createObject(pos, icon, player->getpower());
    _bomb.push_back(bomb);
    ICollider *col = dynamic_cast<ICollider *>(bomb);
    _collider2.push_back(col);
    _collider1[0]->onCollision(col);
  }

  // TODO
  // handle key events.

  Player *player = dynamic_cast<Player *>(_player[0]);
  if (keyInput == 'w') {
    player->setDirection(0, -1);
    player->update();
  }
  if (keyInput == 's') {
    player->setDirection(0, 1);
    player->update();
  }
  if (keyInput == 'a') {
    player->setDirection(-1, 0);
    player->update();
  }
  if (keyInput == 'd') {
    player->setDirection(1, 0);
    player->update();
  }
}

void Controller::update() {}
void reset_terminal() {
  printf("\e[m");    // reset color changes
  printf("\e[?25h"); // show cursor
  fflush(stdout);
  tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

// terminal initial configuration setup
void configure_terminal() {
  tcgetattr(STDIN_FILENO, &old_termios);
  new_termios = old_termios; // save it to be able to reset on exit

  new_termios.c_lflag &= ~(ICANON | ECHO); // turn off echo + non-canonical mode
  new_termios.c_cc[VMIN] = 0;
  new_termios.c_cc[VTIME] = 0;

  tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

  printf("\e[?25l"); // hide cursor
  std::atexit(reset_terminal);
}

int read_input() {
  fflush(stdout);
  char buf[4096]; // maximum input buffer
  int n = read(STDIN_FILENO, buf, sizeof(buf));
  return n > 0 ? buf[n - 1] : -1;
}
