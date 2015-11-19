#include "result.hpp"

Result::Result()
{
  FailCheck(ResTex.Insert("res/result/insect.png", TextureKey::ResultInsect));
  FailCheck(ResMed.Insert("res/sound/result.wav", AudioKey::Result));
}

void Result::Update(){
  if (animation_count % 180 == 0 || App::Get().isPushButton(Mouse::LEFT))
  {
    AnimationChange();
  }

  AnimationUpdate();

  animation_count++;
  if (select_active)
    Select();
}

void Result::Draw(){
  App::Get().bgColor(Color::magenta);

  // 背景
  drawFillBox(background.pos.x(), background.pos.y(), background.size.x(), background.size.y(), image);

  font.size(50);

  //直すべき？
  if (animation == Animation::Select)
  {
    drawTextureBox(-200, -300, 600, 600, 0, 0, 1024, 1024, ResTex.Get(TextureKey::ResultInsect));

    font.draw("タイトルへ", title_f.pos, Color::white);
    font.draw("リトライ", retry_f.pos, Color::white);
  }
  // フェイド用
  drawFillBox(background.pos.x(), background.pos.y(), background.size.x(), background.size.y(), Color(1, 1, 1, fadinf_a));

}

void Result::Select()
{

  if (Collision::MouseToBox(App::Get().mousePosition(), title_f)){
    if (App::Get().isPushButton(Mouse::LEFT)){
      App::Get().flushInput();
      scene_manager->ChangeScene(std::make_shared<Title>());
    }
  }

  if (Collision::MouseToBox(App::Get().mousePosition(), retry_f)){
    if (App::Get().isPushButton(Mouse::LEFT)){
      App::Get().flushInput();
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
    image = Color::olive;
    break;
  case Animation::Door:
    animation = Animation::FadingOut;
    break;
  case Animation::FadingOut:
    break;
  case Animation::Select:
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
    if (FadingOut())
    {
      animation = Animation::Select;
      image = Color::gray;
    }
    break;
  case Animation::Select:
    if (!ResMed.Get(AudioKey::Result).isPlaying()){
      ResMed.Get(AudioKey::Result).play();
    }
    if (FadingIn())
    {
      Select();
    }
    break;
  default:
    break;
  }
}

void Result::TimeReset()
{
  animation_count = 0;
}

bool Result::FadingOut()
{
  if (1 > fadinf_a)
  {
    fadinf_a += 0.01;
    return false;
  }
  if (1 <= fadinf_a){
    return true;
  }
}

bool Result::FadingIn()
{
  if (0 < fadinf_a)
  {
    fadinf_a -= 0.01;
    return false;
  }
  if (0 >= fadinf_a){
    return true;
  }
}