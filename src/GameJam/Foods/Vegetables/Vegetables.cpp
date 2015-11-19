#include "Vegetables.hpp"

Vegetables::Vegetables(){
  type = FoodType::Vegetable;
  variation = (FoodVariation)Rand::Get()(0, 2);
}

Vegetables::~Vegetables(){

}

void Vegetables::Update(){

}

void Vegetables::Draw(){
	drawFillBox(box.pos.x(), box.pos.y(),
		box.size.x(), box.size.y(), Color::green);


}

Box Vegetables::GetBox(){
  return box;
}

void Vegetables::SetBox(Box box)
{
  this->box = box;
}

FoodType Vegetables::GetFoodType(){
  return type;
}

FoodVariation Vegetables::GetFoodVariation(){
  return variation;
}