#include "selectedFood.hpp"

SelectedFood::SelectedFood(Position pos, FoodType type, FoodVariation food_variation){
  switch (pos){
  case Position::Left:
    break;
  case Position::Middle:
    break;
  case Position::Right:
    break;
  }

  this->type = type;
  this->food_variation = food_variation;
}

void SelectedFood::Update(){

}

void SelectedFood::Draw(){
  switch (type){
  case FoodType::Vegetable:
    DrawVegetable(food_variation);
    break;
  case FoodType::Metal:
    //DrawMetal(food_variation);
    break;
  case FoodType::Insect:
    //DrawInsect(food_variation);
    break;
  }
}

void SelectedFood::DrawVegetable(FoodVariation variation){
  switch(food_variation){
  case FoodVariation::Var1:
    break;
  case FoodVariation::Var2:
    break;
  case FoodVariation::Var3:
    break;
  default: 
    break;
  }
}