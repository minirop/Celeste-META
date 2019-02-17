#include "flag.h"
#include "player.h"

Flag::Flag()
  : Object(flag)
{
}

void Flag::init()
{
  x += 5;
  score = 0;
  show = false;

  for (int i = 0; i < 32; i++)
  {
    if (got_fruit[i])
    {
      score++;
    }
  }
}

void Flag::draw()
{
  spr = 118 + static_cast<int>(frames / 5) % 3;
  drawSprite(spr, x, y);
  if (show)
  {
    rectfill(32, 2, 96, 31, 0);
    drawSprite(26, 55, 6);

    char text[16];
    sprintf(text, "x%d", score);
    print(text, 64, 9, 7);
    draw_time(49, 16);
    sprintf(text, "deaths:%d", deaths);
    print(text, 48, 24, 7);
  }
  else if (check(player, 0, 0))
  {
    show = true;
  }
}

