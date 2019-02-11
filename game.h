#ifndef GAME_H
#define GAME_H

#include "constants.h"
#include "playerspawn.h"

class Game
{
public:
  Game();

  void update();
  void draw();

  void load_room(int index);

private:
  State state = State::MAINMENU;
  Image background = Image(128, 128, ColorMode::index);
  Image terrain = Image(128, 128, ColorMode::index);
  Image foreground = Image(128, 128, ColorMode::index);
  u8 solid[MAP_SIZE];
};

#endif

