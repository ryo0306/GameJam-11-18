#pragma once

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../../lib/framework.hpp"
#include "envSingleton.hpp"
#include "../Utility/Collision/collision.hpp"
#include "Resource Manager/resourceManager.hpp"

enum class Position{
  Left,
  Middle,
  Right
};

enum class FoodType{
  Vegetable,
  Metal,
  Insect
};

enum class FoodVariation{
  Var1,
  Var2,
  Var3
};