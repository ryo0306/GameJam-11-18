#pragma once
#include "../../../lib/framework.hpp"
#include "../FoodObject.hpp"

class Insect :public FoodObject{
private:
	Vec2f pos;
	Texture texture;

public:
	Insect();
	~Insect();

	virtual void Update();
	virtual void Draw();
};