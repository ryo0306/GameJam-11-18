#include "Vegetables.hpp"

Vegetables::Vegetables(){

}

Vegetables::~Vegetables(){

}

Texture Vegetables::GetTexture(){
	return m_Texture;
}

void Vegetables::Update(){

}

void Vegetables::Draw(){
	drawTextureBox(m_pos.x(), m_pos.y(), 128, 128, 0, 0, 128, 128, m_Texture);
}