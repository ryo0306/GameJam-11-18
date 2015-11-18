#include "gameMain.hpp"

bool GameMain::LoadSettings(){
  std::fstream stream("settings.json");
  if (!stream.is_open()) return false;
  stream >> this->settings;
  assert(picojson::get_last_error().empty());
  return true;
}

void GameMain::Update(){

}

void GameMain::Draw(){

}