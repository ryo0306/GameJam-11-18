#include "Insect.hpp"

Insect::Insect(){
  type = FoodType::Insect;
  variation = (FoodVariation)Rand::Get()(0, 2);
}

Insect::~Insect(){

}

void Insect::Update(){

}

void Insect::Draw(){
  drawFillBox(box.pos.x(), box.pos.y(),
              box.size.x(), box.size.y(), Color::blue);
}

void Insect::SetBox(Box box)
{
  this->box = box;
}

FoodType Insect::GetFoodType(){
  return type;
}

FoodVariation Insect::GetFoodVariation(){
  return variation;
}