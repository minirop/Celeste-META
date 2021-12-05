#include "game.h"

Game game;
void setup()
{
  gb.begin();
  SerialUSB.begin(9600);
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
