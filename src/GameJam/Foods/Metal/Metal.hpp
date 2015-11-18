#pragma once
#include "../FoodObject.hpp"
#include "../../../lib/framework.hpp"

class Metal :public FoodObjcet{
private:
	Vec2f m_pos;
	int m_AddGauge;
	Texture m_Texture;

public:
	Metal();
	~Metal();

	Texture GetTexture();
	virtual void Update();
	virtual void Draw();

};