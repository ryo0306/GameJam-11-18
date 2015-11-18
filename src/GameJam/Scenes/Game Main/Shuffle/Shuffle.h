#pragma once
#include "lib/framework.hpp"
#include <ctime>
#define FOODTEXTURESIZE 100
#define FOODTOFOODLENGTH 200
#define TIMELIMITMAX 600

class Food
{
private:

public:
  // 変数を継承するため
  Vec2f pos;
  Vec2f size;
  Color image;

  Food(){}

  virtual void Draw(){ drawFillBox(pos.x(), pos.y(), FOODTEXTURESIZE, FOODTEXTURESIZE, image); }
  virtual void Update(){};
//  virtual Texture GetTexture();
  virtual Vec2f GetPos(){ return pos; }
  virtual Color GetColor(){ return image; }       // デバック用
  virtual void SetPos(Vec2f pos_){ pos = pos_; }
};

class Metal : public Food
{
private:
public:
  Metal()
  {
    image = Color::gray;
  }
};

class Vegetable : public Food
{
private:
public:
  Vegetable()
  {
    image = Color::lime;
  }
};

class Insect : public Food
{
private:
  
public:
  Insect()
  {
    image = Color::green;
  }
};


class GameManager
{
private:


  Random rand;
  Food* food[3];
  int time_limit = TIMELIMITMAX;
  int pattern = rand(1,6);
public:

  GameManager()
  {
    Reset();
  }
  void Update();
  void Draw();   //DEBUG
  void Shuffle();
  void Move();
  void Reset();
  void SetFoodPos();
};