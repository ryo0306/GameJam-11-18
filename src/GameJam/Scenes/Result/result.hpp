#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Title/title.hpp"
#include "../../System/commons.hpp"
#include "../../Utility/Collision/collision.hpp"

class Result : public Scene{
private:

  // 名前は(仮)
  enum class Animation
  {
    Dash,
    Door,
    FadingOut, 
    Select,
  };

  enum class Type
  {
    Insect,
    Metal,
    Success,
    Secret,
  };

  Font font = Font("res/meiryo.ttc");
  Box title_f = Box{ Vec2f(-300, -400), Vec2f(250, 50) };
  Box retry_f = Box{ Vec2f(80, -400), Vec2f(200, 50) };
  Box background = Box{ Vec2f(-360, -480), Vec2f(720, 960) };
  Box keepout = Box{ Vec2f(-360, 960), Vec2f(720, 960) };
  int animation_count = 1;     // トイレに駆け込むシーンの切り替え時間
  bool select_active = false;
  Animation animation = Animation::Dash;
  float fadinf_a = 0;

public:
  Result();
  void Update() override;
  void Draw() override;
  void Select();
  void AnimationChange();
  void AnimationUpdate();
  bool FadingOut();
  bool FadingIn();
  void TimeReset();
  void BgmPlay();
  void TypeDecision(/*struct*/);
};