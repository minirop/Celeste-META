#include "balloon.h"
#include "player.h"

Balloon::Balloon()
  : Object(balloon)
{
  spr = 22;
}

void Balloon::init()
{
  offset = rnd(1);
  start = y;
  timer = 0;
  hitbox.x = -1;
  hitbox.y = -1;
  hitbox.w = 10;
  hitbox.h = 10;
}

void Balloon::update()
{
  if (spr == 22)
  {
    offset += 0.04;
    y = start + sin(offset) * 2;
    Object * hit = collide(player, 0, 0);
    if (hit && static_cast<Player*>(hit)->djump < max_djump)
    {
      psfx(6);
      // init smoke
      static_cast<Player*>(hit)->djump = max_djump;
      spr = 0;
      timer = 60;
    }
  }
  else if (timer > 0)
  {
    timer--;
  }
  else
  {
    psfx(7);
    // init smoke
    spr = 22;
  }
}

void Balloon::draw()
{
  if (spr == 22)
  {
    drawSprite(13 + static_cast<int>(offset * 2) % 3, x, y + 6);
    drawSprite(spr, x, y);
  }
}
