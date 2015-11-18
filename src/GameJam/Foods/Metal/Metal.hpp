#pragma once
#include "../FoodObject.hpp"
#include "../../System/commons.hpp"

class Metal :public FoodObject{
private:
	Box box;

public:
	Metal();
	~Metal();

	virtual void Update();
	virtual void Draw();

};