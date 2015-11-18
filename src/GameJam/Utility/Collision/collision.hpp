#pragma once

#include "../../System/commons.hpp"

struct Box{
  Vec2f pos;
  Vec2f size;
};

namespace Collision{
  bool MouseToBox(Vec2f mouse_pos, Box box);
}