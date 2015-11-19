#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Title/title.hpp"
#include "../../System/commons.hpp"
#include "../../Utility/Collision/collision.hpp"

class Result : public Scene{
private:

  Font font = Font("res/meiryo.ttc");
  Color image = Color::gray;    // 本来はTexture
  Box title_f = Box{ Vec2f(-300, -400), Vec2f(250, 50) };
  Box retry_f = Box{ Vec2f(80, -400), Vec2f(200, 50) };
  Box background = Box{ Vec2f(-360, -480), Vec2f(720, 960) };
  Box keepout = Box{ Vec2f(-360, 960), Vec2f(720, 960) };
  int slide_count = 180;     // トイレに駆け込むシーンの切り替え時間
  
public:
  Result();
  void Update() override;
  void Draw() override;
};