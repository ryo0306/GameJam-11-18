#include "../FoodObject.hpp"
#include "../../System/commons.hpp"


class Vegetables :public FoodObject{
private:


public:
	Vegetables();
	~Vegetables();

	virtual void Update();
	virtual void Draw();
  virtual void SetBox(Box box);
};