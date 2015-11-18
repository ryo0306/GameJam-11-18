#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Title/title.hpp"
#include "../../System/commons.hpp"

class Result : public Scene{
private:

public:
  Result() = default;
  void Update() override;
  void Draw() override;
};