#include "Metal.hpp"

Metal::Metal(){
  type = FoodType::Metal;
  variation = (FoodVariation)Rand::Get()(0, 2);
}

Metal::~Metal(){
	
}

void Metal::Update(){

}

void Metal::Draw(){
	/*drawTextureBox(pos.x(), pos.y(), 128, 128, 0, 0, 128, 128, 
		ResourceManager::Texture().Get((int)TextureKey::Metal));*/
	drawFillBox(box.pos.x(), box.pos.y(),
		box.size.x(), box.size.y(), Color::white);
}

void Metal::SetBox(Box box)
{
  this->box = box;
}

FoodType Metal::GetFoodType(){
  return type;
}

FoodVariation Metal::GetFoodVariation(){
  return variation;
}