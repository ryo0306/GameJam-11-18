#include "Vegetables.hpp"

Vegetables::Vegetables(){
	//ResourceManager::Texture().Insert("res/texture.pig")
}

Vegetables::~Vegetables(){

}

void Vegetables::Update(){

}

void Vegetables::Draw(){
	drawFillBox(box.pos.x(), box.pos.y(),
		box.size.x(), box.size.y(), Color::green);


}