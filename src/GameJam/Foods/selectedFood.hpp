#pragma once

#include "../System/commons.hpp"

class SelectedFood{
private:
  Box box; //Change to a Better Name
  FoodType type;
  FoodVariation food_variation;

public:
  SelectedFood(Position pos, FoodType type, FoodVariation food_variation);

  void Update();
  void Draw();

  void DrawVegetable(FoodVariation variation);
  void DrawMetal(FoodVariation variation);
  void DrawInsect(FoodVariation variation);
};