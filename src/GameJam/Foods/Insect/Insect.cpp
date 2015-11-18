#include "Insect.hpp"

Insect::Insect(){

}

Insect::~Insect(){

}

Texture Insect::GetTexture(){
	return m_Texture;
}

void Insect::Update(){

}

void Insect::Draw(){
	drawFillBox(m_pos.x(), m_pos.y(), 128, 128, Color::green);
}