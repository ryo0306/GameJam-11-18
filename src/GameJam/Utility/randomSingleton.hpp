#pragma once

#include "../System/commons.hpp"
#include <ctime>

class Rand{
public:
  static Random& Get(){
    static Random rand;
    rand.setSeed(time(nullptr));
    return rand;
  }
};