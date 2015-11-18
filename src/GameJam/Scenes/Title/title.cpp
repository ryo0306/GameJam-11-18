#include "title.hpp"

void Title::Update(){

}

void Title::Draw(){
  App::Get().bgColor(Color::navy);
  Box test_box{ Vec2f(-200, -300), Vec2f(400, 200) };
  if (Collision::MouseToBox(App::Get().mousePosition(), test_box)){
    drawFillBox(test_box.pos.x(), test_box.pos.y(),
      test_box.size.x(), test_box.size.y(), Color::red);
    if (App::Get().isPushButton(Mouse::LEFT)){
      scene_manager->ChangeScene(std::make_shared<GameMain>());
    }
  }
  else{
  drawFillBox(test_box.pos.x(), test_box.pos.y(),
    test_box.size.x(), test_box.size.y(), Color::white);
  }
}