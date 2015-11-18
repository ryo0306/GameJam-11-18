#include "selectedFood.hpp"

SelectedFood::SelectedFood(Position pos, FoodType type, FoodVariation variation){
  switch (pos){
  case Position::Left:
    food_box = { Vec2f(-250, -100), Vec2f(128, 128) };
    break;
  case Position::Middle:
    food_box = { Vec2f(0, -100), Vec2f(128, 128) };
    break;
  case Position::Right:
    food_box = { Vec2f(250, -100), Vec2f(128, 128) };
    break;
  }

  init_position = pos;
  food_type = type;
  food_variation = variation;
  active = true;
}

bool SelectedFood::IsActive(){
  return active;
}

void SelectedFood::Update(){
  static int counter;
  if (counter > 60){
    active = false;
  }

  switch (init_position){
  case Position::Left:
    food_box.pos.x() += 250.0f / 60.0f;
    food_box.pos.y() += 400.0f / 60.0f;
    break;
  case Position::Middle:
    food_box.pos.y() += 400.0f / 60.0f;
    break;
  case Position::Right:
    food_box.pos.x() -= 250.0f / 60.0f;
    food_box.pos.y() += 400.0f / 60.0f;
    break;
  }
}

void SelectedFood::Draw(){
  switch (food_type){
  case FoodType::Vegetable:
    DrawVegetable(food_variation);
    break;
  case FoodType::Metal:
    DrawMetal(food_variation);
    break;
  case FoodType::Insect:
    DrawInsect(food_variation);
    break;
  }
}

void SelectedFood::DrawVegetable(FoodVariation variation){
  switch(food_variation){
  case FoodVariation::Var1:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::red);
    break;
  case FoodVariation::Var2:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::yellow);
    break;
  case FoodVariation::Var3:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::green);
    break;
  default: 
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::green);
    break;
  }
}

void SelectedFood::DrawMetal(FoodVariation variation){
  switch (food_variation){
  case FoodVariation::Var1:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::black);
    break;
  case FoodVariation::Var2:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::gray);
    break;
  case FoodVariation::Var3:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::white);
    break;
  default:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::white);
    break;
  }
}

void SelectedFood::DrawInsect(FoodVariation variation){
  switch (food_variation){
  case FoodVariation::Var1:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::olive);
    break;
  case FoodVariation::Var2:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::magenta);
    break;
  case FoodVariation::Var3:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::blue);
    break;
  default:
    drawFillBox(food_box.pos.x(), food_box.pos.y(),
      food_box.size.x(), food_box.size.y(), Color::magenta);
    break;
  }
}