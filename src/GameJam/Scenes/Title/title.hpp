#pragma once

#include "../../System/Scene Manager/scene.hpp"
#include "../../System/commons.hpp"

class Title : public Scene{
private:

public:
  void Update() override;
  void Draw() override;
};