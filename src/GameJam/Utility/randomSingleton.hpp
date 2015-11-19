#pragma once

#include "../System/commons.hpp"
#include <ctime>

class Rand{
private:
  Rand();
public:
  Rand(Rand&) = delete;
  static Random& Get(){
    static Random rand;
    rand.setSeed(time(nullptr));
    return rand;
  }
};