#include "Metal.hpp"

Metal::Metal(){

}

Metal::~Metal(){

}

Texture Metal::GetTexture(){
	return m_Texture;
}

void Metal::Update(){

}

void Metal::Draw(){
	drawTextureBox(m_pos.x(), m_pos.y(), 128, 128, 0, 0, 128, 128, m_Texture);
}