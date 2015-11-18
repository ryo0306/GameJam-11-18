#include "Insect.hpp"

Insect::Insect(){
	
}

Insect::~Insect(){

}

void Insect::Update(){

}

void Insect::Draw(){
	drawFillBox(pos.x(), pos.y(), 128, 128, Color::green);
}