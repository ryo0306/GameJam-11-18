#include "result.hpp"

Result::Result()
{
}

void Result::Update(){

  


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
  if (slide_count == 0)
  {
    image = Color::gray;
  }

  if (slide_count > 0)
  {
    slide_count--;
  }

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



  // ”wŒi
  drawFillBox(background.pos.x(), background.pos.y(), background.size.x(), background.size.y(), image);

  // ‚ ‚½‚è”»’è‚ð•`‰æ
  drawFillBox(title_f.pos.x(), title_f.pos.y(), 250, 50, Color::red);
  drawFillBox(retry_f.pos.x(), retry_f.pos.y(), 200, 50, Color::red);

  font.size(50);
  font.draw("ƒ^ƒCƒgƒ‹‚Ö", title_f.pos, Color::white);
  font.draw("ƒŠƒgƒ‰ƒC", retry_f.pos, Color::white);
  

}