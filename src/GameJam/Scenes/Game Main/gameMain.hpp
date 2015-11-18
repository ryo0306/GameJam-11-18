#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Result/result.hpp"
#include "../../System/picojson.h"
#include "../../System/commons.hpp"
#include "../../Foods/FoodObject.hpp"
#include "../../Foods/selectedFood.hpp"
#include <fstream>
#include <cassert>


class GameMain : public Scene{
private:
  picojson::value settings;
  void LoadSettings();
  std::vector<std::shared_ptr<FoodObject>> food;
  std::list<SelectedFood> selected;
public:
  GameMain();
  void Update() override;
  void Draw() override;
};