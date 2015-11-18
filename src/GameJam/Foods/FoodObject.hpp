#pragma once

class FoodObjcet{
private:

public:
	FoodObjcet();
	~FoodObjcet();

	void AddGauge(const int _add, int *_gauge);
	virtual void Update() = 0;
	virtual void Draw() = 0;
};