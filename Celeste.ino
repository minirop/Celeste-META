#include "game.h"

Game * game;
void setup()
{
  gb.begin();
  gb.setFrameRate(30);
  SerialUSB.begin(9600);

  game = new Game;
}

void loop()
{
  while (!gb.update());

  gb.display.clear();

  game->update();
  game->draw();

  gb.display.setCursor(0, 0);
  gb.display.setColor(7);
  //gb.display.printf("dev in progress: %d\nRAM: %d", gb.getCpuLoad(), gb.getFreeRam());
}

