#include "gameMain.hpp"

GameMain::GameMain(){
  Reset();
  FailCheck(ResTex.Insert("res/gameMain/tomoko.png", TextureKey::GameTomoko));
  FailCheck(ResTex.Insert("res/gameMain/plate.png", TextureKey::Plate));
  FailCheck(ResTex.Insert("res/gameMain/vegetables.png", TextureKey::Vegetables));
  FailCheck(ResTex.Insert("res/gameMain/metal.png", TextureKey::Metal));
  FailCheck(ResTex.Insert("res/gameMain/insect.png", TextureKey::Insect));
  FailCheck(ResMed.Insert("res/sound/gameMain.wav", AudioKey::Game));
  FailCheck(ResMed.Insert("res/sound/eating.wav", AudioKey::Eating));
  FailCheck(ResMed.Insert("res/sound/time_out.wav", AudioKey::TimeOut));
  plates[0] = Box{ Vec2f(-325, -320), Vec2f(150, 150) };
  plates[1] = Box{ Vec2f(-75, -320), Vec2f(150, 150) };
  plates[2] = Box{ Vec2f(175, -320), Vec2f(150, 150) };
  timer_pos[0] = Vec2f(-100, 0);
  timer_pos[1] = Vec2f(0, 0);
  timer_pos[2] = Vec2f(100, 0);
  timer_pos[3] = Vec2f(200, 0);
}

void GameMain::Update(){
  if (App::Get().isPushKey('0')){
    ResMed.Get(AudioKey::Game).stop();
    ResMed.Get(AudioKey::TimeOut).play();
    scene_manager->ChangeScene(std::make_shared<Result>());
    return;
  }

  if (!ResMed.Get(AudioKey::Game).isPlaying()){
    ResMed.Get(AudioKey::Game).play();
    ResMed.Get(AudioKey::Game).looping(true);
  }
  if (food_click_limit == 0){
    if (Collision::MouseToBox(App::Get().mousePosition(), food[0]->GetBox())){
      if (App::Get().isPushButton(Mouse::LEFT)){
        ResMed.Get(AudioKey::Eating).play();
        selected.push_back(SelectedFood(Position::Left, food[0]->GetFoodType(), food[0]->GetFoodVariation()));
        Reset();
      }
    }
    
    if (App::Get().isPushKey(GLFW_KEY_LEFT_SHIFT) || App::Get().isPushKey('Z')){
      ResMed.Get(AudioKey::Eating).play();
      selected.push_back(SelectedFood(Position::Left, food[0]->GetFoodType(), food[0]->GetFoodVariation()));
      Reset();
    }

    if (Collision::MouseToBox(App::Get().mousePosition(), food[1]->GetBox())){
      if (App::Get().isPushButton(Mouse::LEFT)){
        ResMed.Get(AudioKey::Eating).play();
        selected.push_back(SelectedFood(Position::Middle, food[1]->GetFoodType(), food[1]->GetFoodVariation()));
        Reset();
      }
    }
    
    if (App::Get().isPushKey(GLFW_KEY_SPACE) || App::Get().isPushKey('B')){
      ResMed.Get(AudioKey::Eating).play();
      selected.push_back(SelectedFood(Position::Middle, food[1]->GetFoodType(), food[1]->GetFoodVariation()));
      Reset();
    }

    if (Collision::MouseToBox(App::Get().mousePosition(), food[2]->GetBox())){
      if (App::Get().isPushButton(Mouse::LEFT) || App::Get().isPushKey(GLFW_KEY_RIGHT_SHIFT)){
        ResMed.Get(AudioKey::Eating).play();
        selected.push_back(SelectedFood(Position::Right, food[2]->GetFoodType(), food[2]->GetFoodVariation()));
        Reset();
      }
    }
    
    if (App::Get().isPushKey(GLFW_KEY_RIGHT_SHIFT) || App::Get().isPushKey(GLFW_KEY_SLASH)){
      ResMed.Get(AudioKey::Eating).play();
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

  drawTextureBox(-360, -480, 720, 960, 0, 0, 720, 960, ResTex.Get(TextureKey::GameTomoko));

  DisplaiedTimer(time_limit);

  if (App::Get().isPushKey('0')){
    scene_manager->ChangeScene(std::make_shared<Result>());
  }

  for (int i = 0; i < 3; i++)
  {
    drawTextureBox(plates[i].pos.x(), plates[i].pos.y(), plates[i].size.x(), plates[i].size.y(),
      0, 0, 512, 512, ResTex.Get(TextureKey::Plate));
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
  food_click_limit = FOODCLICKLIMIT;
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
  food[0]->SetBox(Box{ Vec2f(-325, -300), Vec2f(150, 150) });
  food[1]->SetBox(Box{ Vec2f(-75, -300), Vec2f(150, 150) });
  food[2]->SetBox(Box{ Vec2f(175, -300), Vec2f(150, 150) });
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