#ifndef MESSAGE_H
#define MESSAGE_H

#include "object.h"

class Message : public Object
{
public:
  Message();

  void draw();

private:
  int last = 0;
  int index = 0;
};

#endif

