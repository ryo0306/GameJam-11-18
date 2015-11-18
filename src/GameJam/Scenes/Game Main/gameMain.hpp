#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Result/result.hpp"
#include "../../System/picojson.h"
#include "../../System/commons.hpp"
#include <fstream>
#include <cassert>


class GameMain : public Scene{
private:
  picojson::value settings;
  void LoadSettings();
public:
  GameMain();
  void Update() override;
  void Draw() override;
};