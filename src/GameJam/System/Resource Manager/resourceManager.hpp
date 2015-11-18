#pragma once

#include <map>
#include "../../System/commons.hpp"
#include "resourceKeys.hpp"

namespace hidden{
  class AudioManager{
  private:
    std::map<int, Media> resource;
  public:
    AudioManager() = default;
    void Insert(std::string filepath, int key);
    Media Get(int key);
  };

  class TextureManager{
  private:
    std::map<int, Texture> resource;
  public:
    TextureManager() = default;
    void Insert(std::string filepath, int key);
    Texture Get(int key);
  };
}

class ResourceManager{
public:
  static hidden::AudioManager& Audio(){
    static hidden::AudioManager audio;
    return audio;
  }

  static hidden::TextureManager& Texture(){
    static hidden::TextureManager texture;
    return texture;
  }
};