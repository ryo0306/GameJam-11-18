#include "Insect.hpp"

Insect::Insect(){
	
}

Insect::~Insect(){

}

void Insect::Update(){

}

void Insect::Draw(){
	drawFillBox(box.pos.x(), box.pos.y(),
		box.size.x(), box.size.y(), Color::blue);
}