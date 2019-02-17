#include "game.h"

Game game;
void setup()
{
  gb.begin();
  gb.setFrameRate(30);

  game.init();
}

void loop()
{
  while (!gb.update());

  gb.display.clear();

  game.update();
  game.draw();
}

