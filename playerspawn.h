#ifndef PLAYERSPAWN_H
#define PLAYERSPAWN_H

#include "object.h"
#include "hair.h"

class PlayerSpawn : public Object
{
public:
  PlayerSpawn();

  void init();
  void update();
  void draw();

  void setPosition(int new_x, int new_y);
  void setTarget(int tx, int ty);

private:
  int state = 0;
  int target = 0;
  int delay = 0;

  Hair hair;
};

#endif
