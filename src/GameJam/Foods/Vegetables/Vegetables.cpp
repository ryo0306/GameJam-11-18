#include "Vegetables.hpp"

Vegetables::Vegetables(){

}

Vegetables::~Vegetables(){

}

void Vegetables::Update(){

}

void Vegetables::Draw(){
	drawTextureBox(pos.x(), pos.y(), 128, 128, 0, 0, 128, 128, texture);
}