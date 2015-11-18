#include "../FoodObject.hpp"
#include "../../System/commons.hpp"


class Vegetables :public FoodObject{
private:
	Box box;

public:
	Vegetables();
	~Vegetables();

	virtual void Update();
	virtual void Draw();
};