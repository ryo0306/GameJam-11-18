#include "../FoodObject.hpp"
#include "../../../lib/framework.hpp"


class Vegetables :public FoodObject{
private:
	Vec2f pos;
	Texture texture;

public:
	Vegetables();
	~Vegetables();

	virtual void Update();
	virtual void Draw();
};