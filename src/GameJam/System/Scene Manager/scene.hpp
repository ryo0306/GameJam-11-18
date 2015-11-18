#pragma once

class SceneManager;

class Scene{
protected:
  SceneManager* sceneManager;
public:
  Scene() = default;
  void SetManagerRef(SceneManager* ref){
    sceneManager = ref;
  }
  virtual void Update() = 0;
  virtual void Draw() = 0;
};