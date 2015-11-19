#include "resourceManager.hpp"

void hidden::AudioManager::Insert(std::string filepath, AudioKey key){
  Media temp(filepath);
  resource.insert(std::make_pair(key, temp));
}

Media hidden::AudioManager::Get(AudioKey key){
  return resource.find(key)->second;
}

void hidden::TextureManager::Insert(std::string filepath, TextureKey key){
  Texture temp(filepath);
  resource.insert(std::make_pair(key, temp));
}

Texture hidden::TextureManager::Get(TextureKey key){
  return resource.find(key)->second;
}