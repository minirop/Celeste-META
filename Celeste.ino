#include "game.h"

Game game;
void setup()
{
  gb.begin();
  //SerialUSB.begin(9600);
  gb.setFrameRate(30);

  game.init();
}

void loop()
{
  while (!gb.update());

#ifdef META
  gb.display.clear();
#endif

  game.update();
  game.draw();
}
