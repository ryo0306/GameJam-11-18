#include "result.hpp"

void Result::Update(){

}

void Result::Draw(){
  App::Get().bgColor(Color::magenta);
  Box test_box{ Vec2f(-200, -300), Vec2f(400, 200) };
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
  }
}