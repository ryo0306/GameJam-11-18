#pragma once
#include "../../lib/framework.hpp"

class App{
public:
  static AppEnv& Get(){
    static AppEnv instance(720, 960, false, true);
    return instance;
  }
};