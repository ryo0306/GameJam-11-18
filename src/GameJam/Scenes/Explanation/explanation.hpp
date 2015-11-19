#pragma once
#include "../../System/Scene Manager/sceneManager.hpp"
#include "../../System/commons.hpp"
#include "../Title/title.hpp"

class Explanation :public Scene{
private:

public:
	Explanation() = default;
	void Update() override;
	void Draw() override;
};