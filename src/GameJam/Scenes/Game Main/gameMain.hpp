#pragma once

#include "../../System/Scene Manager/scene.hpp"
#include "../../System/picojson.h"
#include "../../System/commons.hpp"
#include <fstream>
#include <cassert>


class GameMain : public Scene{
private:
  picojson::value settings;
  bool LoadSettings();
public:
  void Update() override;
  void Draw() override;
};