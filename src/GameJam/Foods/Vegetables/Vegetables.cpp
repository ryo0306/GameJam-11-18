#include "Vegetables.hpp"

Vegetables::Vegetables(){
<<<<<<< HEAD
	//ResourceManager::Texture().Insert("res/texture.pig")
=======
	//ResourceManager::Texture().Insert("res/texture.pig",)
>>>>>>> e01371cf529f544ae89ae4a970a708052134cbaa
}

Vegetables::~Vegetables(){

}

void Vegetables::Update(){

}

void Vegetables::Draw(){
	drawFillBox(box.pos.x(), box.pos.y(),
		box.size.x(), box.size.y(), Color::green);


}