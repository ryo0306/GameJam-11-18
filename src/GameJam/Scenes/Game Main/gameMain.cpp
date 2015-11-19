#include "gameMain.hpp"

GameMain::GameMain(){
  Reset();
}

void GameMain::Update(){
  if (food_click_limit == 0){
    if (Collision::MouseToBox(App::Get().mousePosition(), food[0]->GetBox())){
      if (App::Get().isPushButton(Mouse::LEFT)){
        selected.push_back(SelectedFood(Position::Left, food[0]->GetFoodType(), food[0]->GetFoodVariation()));
        Reset();
      }
    }
    else if (App::Get().isPushKey(GLFW_KEY_LEFT_SHIFT)){
      selected.push_back(SelectedFood(Position::Left, food[0]->GetFoodType(), food[0]->GetFoodVariation()));
      Reset();
    }

    if (Collision::MouseToBox(App::Get().mousePosition(), food[1]->GetBox())){
      if (App::Get().isPushButton(Mouse::LEFT)){
        selected.push_back(SelectedFood(Position::Middle, food[1]->GetFoodType(), food[1]->GetFoodVariation()));
        Reset();
      }
    }
    else if (App::Get().isPushKey(GLFW_KEY_SPACE)){
      selected.push_back(SelectedFood(Position::Middle, food[1]->GetFoodType(), food[1]->GetFoodVariation()));
      Reset();
    }

    if (Collision::MouseToBox(App::Get().mousePosition(), food[2]->GetBox())){
      if (App::Get().isPushButton(Mouse::LEFT) || App::Get().isPushKey(GLFW_KEY_RIGHT_SHIFT)){
        selected.push_back(SelectedFood(Position::Right, food[2]->GetFoodType(), food[2]->GetFoodVariation()));
        Reset();
      }
    }
    else if (App::Get().isPushKey(GLFW_KEY_RIGHT_SHIFT)){
      selected.push_back(SelectedFood(Position::Right, food[2]->GetFoodType(), food[2]->GetFoodVariation()));
      Reset();
    }
  }

  for (auto& itr : selected){
    itr.Update();
  }

  UpdateList();

  if (food_click_limit > 0){
    food_click_limit--;
  }
}

void GameMain::Draw(){
  App::Get().bgColor(Color::maroon);

  if (App::Get().isPushKey('0')){
    scene_manager->ChangeScene(std::make_shared<Result>());
  }

  // foodÇÃï`âÊ
  for (int i = 0; i < 3; i++)
  {
    food[i]->Draw();
  }

  for (auto itr : selected){
    itr.Draw();
  }
}


void GameMain::Reset()
{
  pattern = rand(1, 6);
  Shuffle();
  time_limit = TIMELIMITMAX;
  food_click_limit = 10;
}

// Ç±ÇÍÇÇ∑ÇÈÇÒÇæÇ¡ÇΩÇÁà íuÇ
// Ç∏ÇÁÇµÇΩï˚Ç™Ç¢Ç¢Ç©Ç‡ÅHÅH
void GameMain::Shuffle()
{
  switch (pattern)
  {
  case 1:
    food.clear();
    food.emplace_back(std::make_shared<Vegetables>());
    food.emplace_back(std::make_shared<Metal>());
    food.emplace_back(std::make_shared<Insect>());
    break;
  case 2:
    food.clear();
    food.emplace_back(std::make_shared<Vegetables>());
    food.emplace_back(std::make_shared<Insect>());
    food.emplace_back(std::make_shared<Metal>());
    break;
  case 3:
    food.clear();
    food.emplace_back(std::make_shared<Insect>());
    food.emplace_back(std::make_shared<Vegetables>());
    food.emplace_back(std::make_shared<Metal>());
    break;
  case 4:
    food.clear();
    food.emplace_back(std::make_shared<Insect>());
    food.emplace_back(std::make_shared<Metal>());
    food.emplace_back(std::make_shared<Vegetables>());
    break;
  case 5:
    food.clear();
    food.emplace_back(std::make_shared<Metal>());
    food.emplace_back(std::make_shared<Insect>());
    food.emplace_back(std::make_shared<Vegetables>());
    break;
  case 6:
    food.clear();
    food.emplace_back(std::make_shared<Metal>());
    food.emplace_back(std::make_shared<Vegetables>());
    food.emplace_back(std::make_shared<Insect>());
    break;
  }
  SetFoodPos();
}



void GameMain::SetFoodPos()
{
  food[0]->SetBox(Box{ Vec2f(-300, -300), Vec2f(100, 100) });
  food[1]->SetBox(Box{ Vec2f(-50, -300), Vec2f(100, 100) });
  food[2]->SetBox(Box{ Vec2f(200, -300), Vec2f(100, 100) });
}


void GameMain::Move()
{
  for (int i = 0; i < 3; i++)
  {

  }
}

void GameMain::UpdateList(){
  std::list<SelectedFood>::iterator itr = selected.begin();

  if (selected.size() > 1){
    for (itr; itr != selected.end(); itr++){
      if (!itr->IsActive()){
        itr = selected.erase(itr);
      }
    }
  }
  else{
    if (!itr->IsActive()){
      selected.clear();
    }
  }
}