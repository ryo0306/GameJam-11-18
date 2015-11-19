#pragma once

#include <map>
#include "../../System/commons.hpp"
#include "resourceKeys.hpp"

namespace hidden{
  class AudioManager{
  private:
    std::map<AudioKey, Media> resource;
  public:
    AudioManager() = default;
    void Insert(std::string filepath, AudioKey key);
    Media Get(AudioKey key);
  };

  class TextureManager{
  private:
    std::map<TextureKey, Texture> resource;
  public:
    TextureManager() = default;
    void Insert(std::string filepath, TextureKey key);
    Texture Get(TextureKey key);
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