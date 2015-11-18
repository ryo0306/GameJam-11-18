#pragma once
#include "../../../lib/framework.hpp"
#include "../FoodObject.hpp"

class Insect :public FoodObjcet{
private:
	Vec2f m_pos;
	int m_AddGauge;
	Texture m_Texture;

public:
	Insect();
	~Insect();

	Texture GetTexture();
	virtual void Update();
	virtual void Draw();
};