#include "result.hpp"

Result::Result()
{
}

void Result::Update(){

  if (slide_count % 180 == 0 || App::Get().isPushButton(Mouse::LEFT))
  {
    AnimationChange();
  }

  AnimationUpdate();

  if (select_active)
  Select();


  slide_count++;
}

void Result::Draw(){
  App::Get().bgColor(Color::magenta);
  /*Box test_box{ Vec2f(-200, -300), Vec2f(400, 200) };
  if (Collision::MouseToBox(App::Get().mousePosition(), test_box)){
    drawFillBox(test_box.pos.x(), test_box.pos.y(),
      test_box.size.x(), test_box.size.y(), Color::red);
    if (App::Get().isPushButton(Mouse::LEFT)){
      scene_manager->ChangeScene(std::make_shared<Title>());
    }
  }
  else{
    drawFillBox(test_box.pos.x(), test_box.pos.y(),
      test_box.size.x(), test_box.size.y(), Color::white);
  }*/



  // 背景
  drawFillBox(background.pos.x(), background.pos.y(), background.size.x(), background.size.y(), image);

  // あたり判定を描画
  //drawFillBox(title_f.pos.x(), title_f.pos.y(), 250, 50, Color::red);
  //drawFillBox(retry_f.pos.x(), retry_f.pos.y(), 200, 50, Color::red);

  font.size(50);
  //直すべき？
  if (animation == Animation::Select)
  {
    font.draw("タイトルへ", title_f.pos, Color::white);
    font.draw("リトライ", retry_f.pos, Color::white);
  }
  // フェイド用
  drawFillBox(background.pos.x(), background.pos.y(), background.size.x(), background.size.y(), Color(1,1,1,fedinf_a));

}

void Result::Select()
{

  if (Collision::MouseToBox(App::Get().mousePosition(), title_f)){
    if (App::Get().isPushButton(Mouse::LEFT)){
      scene_manager->ChangeScene(std::make_shared<Title>());
    }
  }

  if (Collision::MouseToBox(App::Get().mousePosition(), retry_f)){
    if (App::Get().isPushButton(Mouse::LEFT)){
      scene_manager->ChangeScene(std::make_shared<GameMain>());
    }
  }

}



void Result::AnimationChange()
{ 
  //TODO:切り替えはどうするか考える
  switch (animation)
  {
  case Animation::Toilet:
    animation = Animation::Door;
    image = Color::blue;
    break;
  case Animation::Door:
    animation = Animation::FadingOut;
    image = Color::olive;
    break;
  case Animation::FadingOut:
    animation = Animation::Select;
    break;
  case Animation::Select:
    image = Color::gray;
    break;
  default:
    break;
  }

  TimeReset();

}

void Result::AnimationUpdate()
{

  switch (animation)
  {
  case Animation::Toilet:
    break;
  case Animation::Door:
    break;
  case Animation::FadingOut:
    FedingOut();
    break;
  case Animation::Select:
    FedingIn();
    break;
  default:
    break;
  }
}


void Result::TimeReset()
{
  slide_count = 1;
}

void Result::FedingOut()
{
  if (1 <= fedinf_a)
    fedinf_a += 0.005;
}

void Result::FedingIn()
{
  if (0 >= fedinf_a)
    fedinf_a -= 0.005;
}