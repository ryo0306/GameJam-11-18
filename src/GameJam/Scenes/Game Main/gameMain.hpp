#pragma once

#include "../../System/Scene Manager/sceneManager.hpp"
#include "../Result/result.hpp"
#include "../../System/commons.hpp"
#include "../../Foods/FoodObject.hpp"
#include "../../Foods/selectedFood.hpp"
#include "../../Foods/Insect/Insect.hpp"
#include "../../Foods/Metal/Metal.hpp"
#include "../../Foods/Vegetables/Vegetables.hpp"
#include <fstream>
#include <vector>

#define FOODTEXTURESIZE 100
#define FOODTOFOODLENGTH 200
#define TIMELIMITMAX 600
#define FOODCLICKLIMIT 5

class GameMain : public Scene{
private:
  void LoadSettings();
  std::vector<std::shared_ptr<FoodObject>> food;
  std::list<SelectedFood> selected;
  Box plates[3];

  Random rand;
  Font timer_font = Font("res/meiryo.ttc");
  int time_limit = TIMELIMITMAX;
  std::vector<int> time_vector;
  Vec2f timer_pos[4];
  int pattern = rand(1, 6);
  int food_click_limit = 0;

public:
  GameMain();
  void Update() override;
  void Draw() override;
  void Shuffle();
  void Reset();
  void SetFoodPos();
  void UpdateList();
  void DisplaiedTimer(int _time);
  void SwitchNomber(int _value,Vec2f _vec);
};