#include "explanation.hpp"

void Explanation::Update(){

}

void Explanation::Draw(){
	App::Get().bgColor(Color::olive);
	Box return_title_box{ Vec2f(-200, -400), Vec2f(400, 100) };
	if (Collision::MouseToBox(App::Get().mousePosition(), return_title_box)){
		drawFillBox(return_title_box.pos.x(), return_title_box.pos.y(),
			return_title_box.size.x(), return_title_box.size.y(), Color::red);
		if (App::Get().isPushButton(Mouse::LEFT)){
			scene_manager->ChangeScene(std::make_shared<Title>());
		}
	}
	else{
		drawFillBox(return_title_box.pos.x(), return_title_box.pos.y(),
			return_title_box.size.x(), return_title_box.size.y(), Color::white);
	}

}