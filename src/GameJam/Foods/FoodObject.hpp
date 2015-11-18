#pragma once
#include "../System/commons.hpp"

class FoodObject{
private:

protected:
  Box box;
public:
	FoodObject();
	~FoodObject();

	void AddGauge(const int _add, int *_gauge);
	virtual void Update() = 0;
	virtual void Draw() = 0;
  virtual void SetBox(Box box) = 0;
};