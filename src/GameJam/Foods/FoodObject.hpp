#pragma once

class FoodObject{
private:

public:
	FoodObject();
	~FoodObject();

	void AddGauge(const int _add, int *_gauge);
	virtual void Update() = 0;
	virtual void Draw() = 0;
};