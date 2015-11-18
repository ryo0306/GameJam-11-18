#include "Shuffle.h"

// 位置が決まっている
// 中身のクラスだけ入れ替える
// 

void GameManager::Update()
{
  if (time_limit <= 0)
  {
    Move();
    Reset();
  }

  //TODO:関数化
  time_limit--;
}


void GameManager::Draw()
{
  for (int i = 0; i < 3; i++)
  {
    food[i]->Draw();
  }
}

void GameManager::Reset()
{
  pattern = rand(1, 6);
  Shuffle();
  time_limit = TIMELIMITMAX;
}

// これをするんだったら位置を
// ずらした方がいいかも？？
void GameManager::Shuffle()
{
  switch (pattern)
  {
  case 1:
    food[0] = new Vegetable();
    food[1] = new Metal();
    food[2] = new Insect();
    break;
  case 2:
    food[0] = new Vegetable();
    food[1] = new Insect();
    food[2] = new Metal();
    break;
  case 3:
    food[0] = new Insect();
    food[1] = new Vegetable();
    food[2] = new Metal();
    break;
  case 4:
    food[0] = new Insect();
    food[1] = new Metal();
    food[2] = new Vegetable();
    break;
  case 5:
    food[0] = new Metal();
    food[1] = new Insect();
    food[2] = new Vegetable();
    break;
  case 6:
    food[0] = new Metal();
    food[1] = new Vegetable();
    food[2] = new Insect();
    break;
  default:
    break;
  }
  SetFoodPos();
}



void GameManager::SetFoodPos()
{
  food[0]->SetPos(Vec2f(250, -100));
  food[1]->SetPos(Vec2f(-50, -100));
  food[2]->SetPos(Vec2f(-350, -100));
}


void GameManager::Move()
{
  for (int i = 0; i < 3; i++)
  {
    
  }
}