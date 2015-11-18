#include "../FoodObject.hpp"
#include "../../../lib/framework.hpp"


class Vegetables :public FoodObjcet{
private:
	Vec2f m_pos;
	int m_AddGauge;
	Texture m_Texture;

public:
	Vegetables();
	~Vegetables();

	Texture GetTexture();
	virtual void Update();
	virtual void Draw();
};