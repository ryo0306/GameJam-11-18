#include "gameMain.hpp"

GameMain::GameMain(){
  Reset();
}

void GameMain::LoadSettings(){
  std::fstream stream("settings.json");
  if (!stream.is_open()) return;
  stream >> this->settings;
  assert(picojson::get_last_error().empty());
}

void GameMain::Update(){

  if (time_limit <= 0)
  {
    Move();
    Reset();
  }

  //TODO:ŠÖ”‰»
  time_limit--;
}

void GameMain::Draw(){
  App::Get().bgColor(Color::olive);
  /*Box test_box{ Vec2f(-200, -300), Vec2f(400, 200) };
  if (Collision::MouseToBox(App::Get().mousePosition(), test_box)){
    drawFillBox(test_box.pos.x(), test_box.pos.y(),
      test_box.size.x(), test_box.size.y(), Color::red);
    if (App::Get().isPushButton(Mouse::LEFT)){
      scene_manager->ChangeScene(std::make_shared<Result>());
    }
  }
  else{
    drawFillBox(test_box.pos.x(), test_box.pos.y(),
      test_box.size.x(), test_box.size.y(), Color::white);
  }*/

  // food‚Ì•`‰æ
  for (int i = 0; i < 3; i++)
  {
    food[i]->Draw();
  }
}


void GameMain::Reset()
{
  pattern = rand(1, 6);
  Shuffle();
  time_limit = TIMELIMITMAX;
}

// ‚±‚ê‚ð‚·‚é‚ñ‚¾‚Á‚½‚çˆÊ’u‚ð
// ‚¸‚ç‚µ‚½•û‚ª‚¢‚¢‚©‚àHH
void GameMain::Shuffle()
{
  switch (pattern)
  {
  case 1:
    food[0] = new Vegetables();
    food[1] = new Metal();
    food[2] = new Insect();
    break;
  case 2:
    food[0] = new Vegetables();
    food[1] = new Insect();
    food[2] = new Metal();
    break;
  case 3:
    food[0] = new Insect();
    food[1] = new Vegetables();
    food[2] = new Metal();
    break;
  case 4:
    food[0] = new Insect();
    food[1] = new Metal();
    food[2] = new Vegetables();
    break;
  case 5:
    food[0] = new Metal();
    food[1] = new Insect();
    food[2] = new Vegetables();
    break;
  case 6:
    food[0] = new Metal();
    food[1] = new Vegetables();
    food[2] = new Insect();
    break;
  default:
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