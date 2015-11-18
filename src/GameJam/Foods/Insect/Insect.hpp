#pragma once
#include "../FoodObject.hpp"
#include "../../System/commons.hpp"

class Insect :public FoodObject{
private:
	Box box;

public:
	Insect();
	~Insect();

	virtual void Update();
	virtual void Draw();
};