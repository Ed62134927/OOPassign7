#include "AnsiPrint.h"
#include "controller.h"
#include "view.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

#include "BombFactory.h"
#include "PlaceobjFactory.h"
#include "PlayerFactory.h"
#include "iconFactory.h"
/**
 * Print my id
 * */
void PrintMyID(std::string studId) {

  std::string str = "ID: " + studId;
  std::cout << AnsiPrint(str.c_str(), YELLOW, RED, true, true) << std::endl
            << std::endl;
}

int main() {
  // TODO
  // Integrate the Simple MVC Pattern to run the program.

  srand(time(0));

  std::cout << "Welcome to the Bomb Game!" << std::endl;
  int player;
  std::cout << "Please select your player(1:RED,2:GREEN,3:BLUE,4:PINK): ";

  std::cin >> player;
  std::cout << std::endl;
  int mode;

  std::cout << "Please select your mode(1:easy,2:medium,3:hard): ";
  std::cin >> mode;
  std::cout << std::endl;

  View view;
  Controller controller(view);
  if (mode == 1) {
    if (player == 1) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 3, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 1, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 1, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 1, "Player 4"));
    } else if (player == 2) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 3, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 1, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 1, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 1, "Player 4"));
    } else if (player == 3) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 3, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 1, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 1, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 1, "Player 4"));
    } else if (player == 4) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 3, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 1, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 1, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 1, "Player 4"));
    }
  } else if (mode == 2) {
    if (player == 1) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 3, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 2, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 2, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 2, "Player 4"));
    } else if (player == 2) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 3, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 2, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 2, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 2, "Player 4"));
    } else if (player == 3) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 3, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 2, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 2, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 2, "Player 4"));
    } else if (player == 4) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 3, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 2, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 2, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 2, "Player 4"));
    }
  } else if (mode == 3) {
    if (player == 1) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 2, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 3, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 3, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 3, "Player 4"));
    } else if (player == 2) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 2, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 3, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 3, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 3, "Player 4"));
    } else if (player == 3) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 2, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 3, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 3, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 3, "Player 4"));
    } else if (player == 4) {
      Position pos1;
      pos1.e1 = 1;
      pos1.e2 = 19;
      Direction dir1;
      dir1.x = 0;
      dir1.y = 1;
      Icon icon = IconFactory::createIcon(Color::PINK, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos1, icon, dir1, 2, "Player 1"));
      Position pos2;
      pos2.e1 = 1;
      pos2.e2 = 1;
      Direction dir2;
      dir2.x = -1;
      dir2.y = 0;
      Icon icon2 = IconFactory::createIcon(Color::GREEN, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos2, icon2, dir2, 3, "Player 2"));
      Position pos3;
      pos3.e1 = 19;
      pos3.e2 = 1;
      Direction dir3;
      dir3.x = 0;
      dir3.y = 1;
      Icon icon3 = IconFactory::createIcon(Color::BLUE, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos3, icon3, dir3, 3, "Player 3"));
      Position pos4;
      pos4.e1 = 19;
      pos4.e2 = 19;
      Direction dir4;
      dir4.x = 0;
      dir4.y = -1;
      Icon icon4 = IconFactory::createIcon(Color::RED, "P");
      controller.addPlayer(
          PlayerFactory::createObject(pos4, icon4, dir4, 3, "Player 4"));
    }
  }
  Position pos5;
  pos5.e1 = 13;
  pos5.e2 = 7;
  Icon icon5 = IconFactory::createIcon(Color::NOCHANGE, "+");
  controller.addPlace(
      PlaceobjFactory::createObject(pos5, icon5, 0, POWER, 10000));
  Position pos6;
  pos6.e1 = 3;
  pos6.e2 = 15;
  Icon icon6 = IconFactory::createIcon(Color::NOCHANGE, "+");
  controller.addPlace(
      PlaceobjFactory::createObject(pos6, icon6, 0, POWER, 10000));
  for (int i = 0; i < 20; i++) {
    Position pos;
    pos.e1 = 0 + i;
    pos.e2 = 10;
    Icon icon = IconFactory::createIcon(Color::BLACK, "R");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, ROCK, 10000));
  }
  for (int i = 0; i < 20; i++) {
    Position pos;
    pos.e1 = 0 + i;
    pos.e2 = 11;
    Icon icon = IconFactory::createIcon(Color::BLACK, "R");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, ROCK, 10000));
  }
  for (int i = 0; i < 20; i++) {
    Position pos;
    pos.e1 = 10;
    pos.e2 = 0 + i;
    Icon icon = IconFactory::createIcon(Color::BLACK, "R");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, ROCK, 10000));
  }
  for (int i = 0; i < 20; i++) {
    Position pos;
    pos.e1 = 11;
    pos.e2 = 0 + i;
    Icon icon = IconFactory::createIcon(Color::BLACK, "R");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, ROCK, 10000));
  }
  for (int i = 2; i < 8; i++) {
    Position pos;
    pos.e1 = i;
    pos.e2 = 8;
    Icon icon = IconFactory::createIcon(Color::BLACK, "G");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, GRASS, 10000));
  }
  for (int i = 2; i < 4; i++) {
    Position pos;
    pos.e1 = 7;
    pos.e2 = i;
    Icon icon = IconFactory::createIcon(Color::BLACK, "T");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, TREE, 10000));
  }
  for (int i = 14; i < 18; i++) {
    Position pos;
    pos.e1 = 6;
    pos.e2 = i;
    Icon icon = IconFactory::createIcon(Color::BLACK, "T");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, TREE, 10000));
  }
  for (int i = 14; i < 18; i++) {

    Position pos;
    pos.e1 = i;
    pos.e2 = 6;
    Icon icon = IconFactory::createIcon(Color::BLACK, "T");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, TREE, 10000));
    pos.e1 = i - 2;
    pos.e2 = 13;
    icon = IconFactory::createIcon(Color::BLACK, "T");
    controller.addPlace(
        PlaceobjFactory::createObject(pos, icon, 0, TREE, 10000));
  }

  controller.run();

  PrintMyID("111303007");
  return 0;
}
