#include "Metal.hpp"

Metal::Metal(){
	//ResourceManager::Texture().Insert("res/texture.png", (int)TextureKey::Metal);
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