#include "platform.h"

Platform::Platform(int dir)
  : Object(platform), dir(dir)
{
}

void Platform::init()
{
  x -= 4;
  solids = false;
  hitbox.w = 16;
  last = x;
}

void Platform::update()
{
  Object::update();
  
  spd.x = dir * 0.65;
  
  if (x < -SCREEN_H_OFFSET) x = MAP_SIZE;
  else if (x > MAP_SIZE) x = -SCREEN_H_OFFSET;

  if (!check(player, 0, 0))
  {
    Object * hit = collide(player, 0, -1);
    if (hit)
    {
      hit->move_x(x - last, 1);
    }
  }

  last = x;
}

void Platform::draw()
{
  drawSprite(11, x,     y - 1);
  drawSprite(12, x + 8, y - 1);
}
