#include "gameMain.hpp"

GameMain::GameMain(){
  Reset();
  FailCheck(ResTex.Insert("res/gameMain/plate.png", TextureKey::Plate));
  FailCheck(ResTex.Insert("res/gameMain/vegetables.png", TextureKey::Vegetables));
  FailCheck(ResTex.Insert("res/gameMain/metal.png", TextureKey::Metal));
  FailCheck(ResTex.Insert("res/gameMain/insect.png", TextureKey::Insect));
  timer_pos[0] = Vec2f(-100, 0);
  timer_pos[1] = Vec2f(0, 0);
  timer_pos[2] = Vec2f(100, 0);
  timer_pos[3] = Vec2f(200, 0);
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
  time_limit--;
}

void GameMain::Draw(){
  App::Get().bgColor(Color::maroon);

  DisplaiedTimer(time_limit);


  if (App::Get().isPushKey('0')){
    scene_manager->ChangeScene(std::make_shared<Result>());
  }

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

void GameMain::DisplaiedTimer(int _time){
	int time = (_time * 10) / 6;
	while (time != 0){
		time_vector.push_back(time % 10);
		time /= 10;
	}
//	int enpty_time = 4 - time_vector.size();
	int enpty_time = 4;
	timer_font.size(50);
	for (int i = 0; i < enpty_time; ++i){
		timer_font.draw("0", timer_pos[i], Color::white);
	}


	//for (int i = time_vector.size() - 1; i >= 0; --i){
	//	SwitchNomber(time_vector[i], timer_pos[i]);
	//}
	time_vector.empty();
}

void GameMain::SwitchNomber(int _value,Vec2f _vec){
	switch (_value){
	case 0:
		timer_font.draw("0", _vec, Color::white);
		break;

	case 1:
		timer_font.draw("1", _vec, Color::white);
		break;

	case 2:
		timer_font.draw("2", _vec, Color::white);
		break;

	case 3:
		timer_font.draw("3", _vec, Color::white);
		break;

	case 4:
		timer_font.draw("4", _vec, Color::white);
		break;

	case 5:
		timer_font.draw("5", _vec, Color::white);
		break;

	case 6:
		timer_font.draw("6", _vec, Color::white);
		break;

	case 7:
		timer_font.draw("7", _vec, Color::white);
		break;

	case 8:
		timer_font.draw("8", _vec, Color::white);
		break;

	case 9:
		timer_font.draw("9", _vec, Color::white);
		break;

	default:
		timer_font.draw("0", _vec, Color::white);
		break;
	}
}