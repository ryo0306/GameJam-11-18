#include "resourceManager.hpp"

void hidden::AudioManager::Insert(std::string filepath, int key){
  Media temp(filepath);
  resource.insert(std::make_pair(key, temp));
}

Media hidden::AudioManager::Get(int key){
  return resource.find(key)->second;
}

void hidden::TextureManager::Insert(std::string filepath, int key){
  Texture temp(filepath);
  resource.insert(std::make_pair(key, temp));
}

Texture hidden::TextureManager::Get(int key){
  return resource.find(key)->second;
}