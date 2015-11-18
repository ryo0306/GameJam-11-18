#include "GameJam/System/Scene Manager/sceneManager.hpp"
#include "GameJam/System/commons.hpp"

int main() {
  App::Get();
  while (App::Get().isOpen()) {
    App::Get().begin();
    
    App::Get().end();
  }
}
