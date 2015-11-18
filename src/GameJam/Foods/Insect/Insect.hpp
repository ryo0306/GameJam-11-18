#pragma once
#include "../FoodObject.hpp"
#include "../../System/commons.hpp"

class Insect :public FoodObject{
private:

public:
	Insect();
	~Insect();

	virtual void Update();
	virtual void Draw();
  virtual void SetBox(Box box);

};