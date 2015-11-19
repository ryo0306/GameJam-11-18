#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Game Main/gameMain.hpp"
#include "../Explanation/explanation.hpp"
#include "../../System/commons.hpp"

class Title : public Scene{
private:

public:
  Title() = default;
  void Update() override;
  void Draw() override;
};